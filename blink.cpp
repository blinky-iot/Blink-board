#include "esp32-hal-gpio.h"
#include "blink.h"

#define DEBUG_PRINT 0  // Set to 1 to enable debug prints, 0 to disable
#define USE_GSM true

Blink::Blink(SPIClass &spi, TwoWire &wire) {
    this->spi = &spi;
    this->spi->begin();
    this->wire = &wire;
    this->wire->begin(); 
    m_PWMValues = nullptr;
}

Blink::~Blink() {
    if (m_PWMValues != nullptr) {
        free(m_PWMValues);
    }
}

void Blink::begin() {
    pinMode(cs, OUTPUT);
    digitalWrite(cs, HIGH);
    pinMode(SS, OUTPUT);
    digitalWrite(SS, HIGH);
    #if USE_GSM
    pinMode(Sim_pwrkey, OUTPUT);
    #endif
}

void Blink::gsm_begin() {
  unsigned long startTime = millis();
  const unsigned long pulseDuration = 100;
  
  digitalWrite(Sim_pwrkey, HIGH);
  
  while (millis() - startTime < pulseDuration) {
    // Wait for 100ms
  }
  
  digitalWrite(Sim_pwrkey, LOW);
  
  while (millis() - startTime < 2 * pulseDuration) {
    // Wait for another 100ms
  }
  
  digitalWrite(Sim_pwrkey, HIGH);
  
  Serial2.write("AT+IPR=9600\r\n");
  Serial2.end();
  Serial2.begin(9600);
}

bool Blink::isConnected(){
  // Serial.println(strnlen(_address, sizeof(_address)));
  if(_address[0] =='\0' ){
    return false;
  }else {
    // for(int i =0; i < strnlen(_address, sizeof(_address));i++){
      
    // }
  return true;
  }
}

char* Blink::wirescan(){
  uint8_t error;
  int devices = 0;
  _address[255] = {0};
  char* ptr = _address;

  for(uint8_t address = 0x01; address < 0x7f; address++){
    wire->beginTransmission(address);
    error = wire->endTransmission();
    if(error == 0){
      if(devices>0){
        *ptr++ =',';
      }
      ptr += sprintf(ptr, "0x%02X",address);
      devices++;
    }
    delay(1);
  }
  return _address;
}

bool Blink::digitalRead(uint8_t pin, uint8_t addr){
  readbuf = 0;
  uint8_t received = wire->requestFrom(addr,1);
  if ((bool)received) {  //If received more than zero bytes
    wire->readBytes((uint8_t *) &readbuf, received);
    return(readbuf >> pin) & 0x01;
  }
}

bool Blink::digitalRead(uint8_t pin){
  // pin = pin -1;
  readbuf = 0;
  uint8_t addr = PCF8574_I2CADDR1_DEFAULT;
  uint8_t received = wire->requestFrom(addr,1);
  if ((bool)received) {  //If received more than zero bytes
    wire->readBytes((uint8_t *) &readbuf, received);
    return(readbuf >> pin) & 0x01;
  }
  return received;
}

uint16_t Blink::analogRead(uint8_t channel) {
    spi->beginTransaction(SPISettings(spianalogClk, MSBFIRST, SPI_MODE0));
    uint8_t addr = 0b01100000 | ((channel & 0b111) << 2);
    digitalWrite(cs, LOW);
    spi->transfer(addr);
    uint8_t byte1 = spi->transfer(0x00);
    uint8_t byte2 = spi->transfer(0x00);
    digitalWrite(cs, HIGH);
    spi->endTransaction();
    uint16_t result = ((byte1 << 4) | (byte2 >> 4));

    #if DEBUG_PRINT
    Serial.printf("Analog read channel %d: %d\n", channel, result);
    #endif

    return result;
}

void Blink::boardcount(int board) {
    this->bitCount = board * 8;
    this->byteCount = (board * 8) / 8;
    for (int i = 0; i < this->byteCount; i++) {
        this->writeBuffer[i] = 0;
    }

    #if DEBUG_PRINT
    Serial.printf("Board count set to %d, byteCount: %d\n", board, this->byteCount);
    #endif
}

void Blink::writeDigital(int pin, bool value) {
  if(pin==0)pin=1;
  int bytenum = (pin-1) / 8;
  int offset = (pin-1) % 8;
  byte b = this->writeBuffer[bytenum];
  bitWrite(b, offset, value);
  this->writeBuffer[bytenum] = b;
  writebyte();
}

void Blink::writeDigital(int pin, int board, bool value) {
    if (pin == 0) pin = 1;
    pin = pin + (board * 8);
    int bytenum = (pin - 1) / 8;
    int offset = (pin - 1) % 8;
    // Error: Pin %d on board %d is out of range
    if (bytenum >= this->byteCount) {
        return;
    }
    
    byte b = this->writeBuffer[bytenum];
    bitWrite(b, offset, value);
    this->writeBuffer[bytenum] = b;

    writebyte();
}

void Blink::writebyte() {
   //SPI serial interface (modes 0,0 and 1,1)ref https://ww1.microchip.com/downloads/en/devicedoc/21298e.pdf
    spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
    digitalWrite(SS, LOW);
    spi->transfer(this->writeBuffer, this->byteCount);
    digitalWrite(SS, HIGH);

    spi->endTransaction();
}

void IRAM_ATTR onTimer() {
    // Implement your timer interrupt handler here
}

// void Blink::InitTimer(uint32_t frequency) {
//     timer = timerBegin(0, 80, true);  // 80 is prescaler, true for count up
//     timerAttachInterrupt(timer, &onTimer, true);
//     timerAlarmWrite(timer, 1000000 / frequency, true);
//     timerAlarmEnable(timer);

//     #if DEBUG_PRINT
//     Serial.printf("Timer initialized with frequency %d Hz\n", frequency);
//     #endif
// }