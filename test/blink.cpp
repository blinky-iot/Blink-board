#include "esp32-hal-gpio.h"
#include "blink.h"

Blink::Blink(SPIClass &spi,TwoWire &wire) {
  // delete(spi);
  this->spi = &spi;
	this->spi->begin();
  // this->wire->begin();
	unsigned char * m_PWMValues=0;
  // this->spi->beginTransaction(SPISettings(spiClk,MSBFIRST,SPI_MODE0));
}

Blink::~Blink(){
  // if(m_PWMValues > 0){
  //   free(m_PWMValues);
  // }
}

void Blink::begin() {
	pinMode(cs, OUTPUT);
	digitalWrite(cs, HIGH);
  //SPI serial interface (modes 0,0 and 1,1)ref https://ww1.microchip.com/downloads/en/devicedoc/21298e.pdf
  spi->beginTransaction(SPISettings(spianalogClk, MSBFIRST, SPI_MODE0));

  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
	}

uint16_t Blink::analogRead(uint8_t channel) {
	uint8_t addr = 0b01100000 | ((channel & 0b111) << 2);
	digitalWrite(cs, LOW);                // Set the chip select pin LOW to start SPI communication
	spi->transfer(addr);                  // Send the address byte over SPI
	uint8_t byte1 = spi->transfer(0x00);  // Receive the first byte of data from SPI
	uint8_t byte2 = spi->transfer(0x00);  // Receive the second byte of data from SPI
	digitalWrite(cs, HIGH);               //set the chip select pin HIGH to end SPI communication
  return ((byte1 << 4) | (byte2 >> 4));
	}

 void Blink::boardcount(int board) {
  this->bitCount = board * 8;
  this->byteCount = (board * 8)/8;
  for(int i = 0; i < this->byteCount; i++) {
    this->writeBuffer[i] = 0;
  }
} 

bool Blink::digitalRead(uint8_t pin){}

bool Blink::isConnected(){}

void Blink::set_pwm(int pin, unsigned int value){
  int bytenum = (pin-1) / 8;
  int offset = (pin-1) % 8;
  byte b = this->writeBuffer[bytenum];
  Serial.println(b);
  bitWrite(b, offset, value);
  this->writeBuffer[bytenum] = b;
  Serial.println(writeBuffer[bytenum]);
  // writebyte();
}
void Blink::pwm_start(uint32_t frequency){
  InitTimer(frequency);
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

void Blink::writeDigital(int pin, int board,bool value) {
  if(pin==0)pin=1;
  pin = pin + (board*8);
  int bytenum = (pin-1) / 8;
  int offset = (pin-1) % 8;
  byte b = this->writeBuffer[bytenum];
  bitWrite(b, offset, value);
  this->writeBuffer[bytenum] = b;
  writebyte();
}
void Blink::writebyte() {
  // spi->beginTransaction(SPISettings(spiClk, LSBFIRST, SPI_MODE0));
  digitalWrite(SS, LOW);
  for(int i = 0; i < this->byteCount; i++) {
    spi->transfer(this->writeBuffer[i]);
    delay(50);
  }
  digitalWrite(SS, HIGH);
}

void IRAM_ATTR onTimer() {
    //ShiftPWM_handleInterrupt();
}

void Blink::InitTimer(uint32_t frequency){
   // Set timer frequency to 1Mhz
  timer = timerBegin(frequency);
  // Attach onTimer function to our timer.
  timerAttachInterrupt(timer, &onTimer);
  // Set alarm to call onTimer function every second (value in microseconds).
  // Repeat the alarm (third parameter) with unlimited count = 0 (fourth parameter).
  timerAlarm(timer, 1000000, true, 0);
  // timerAlarmEnable(timer);
}