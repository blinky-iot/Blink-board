#include "HardwareSerial.h"
#include "Arduino.h"
#include <stdint.h>
#include <stdio.h>
#include "HardwareSerial.h"
// #include "WString.h"
// #include <stdint.h>
#include "Wire.h"
#include "blink.h"

Blink::Blink(SPIClass &spi,TwoWire &wire) {
  this->spi = &spi;
  this->wire = &wire;
  this->wire->begin();
	unsigned char * m_PWMValues=nullptr;
}

Blink::~Blink(){
  // if(m_PWMValues > 0){
  //   free(m_PWMValues);
  // }
}

void Blink::begin() {
	pinMode(cs, OUTPUT);
	digitalWrite(cs, HIGH);
  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
  spi->begin(SCK, MISO, MOSI, -1);
  wirescan();
	}

void Blink::gsm_begin() {
  pinMode(Sim_pwrkey, OUTPUT);
  
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

uint16_t Blink::analogRead(uint8_t channel) {
  spi->beginTransaction(SPISettings(spianalogClk, MSBFIRST, SPI_MODE0));
	uint8_t addr = 0b01100000 | ((channel & 0b111) << 2);
	digitalWrite(cs, LOW);                // Set the chip select pin LOW to start SPI communication
	spi->transfer(addr);                  // Send the address byte over SPI
	uint8_t byte1 = spi->transfer(0x00);  // Receive the first byte of data from SPI
	uint8_t byte2 = spi->transfer(0x00);  // Receive the second byte of data from SPI
	digitalWrite(cs, HIGH);               //set the chip select pin HIGH to end SPI communication
  spi->endTransaction();
  return ((byte1 << 4) | (byte2 >> 4));
	}

 void Blink::boardcount(int board) {
  this->bitCount = board * 8;
  this->byteCount = (board * 8)/8;
  for(int i = 0; i < this->byteCount; i++) {
    this->writeBuffer[i] = 0;
  }
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
  pin = pin -1;
  readbuf = 0;
  uint8_t addr = PCF8574_I2CADDR1_DEFAULT;
  uint8_t received = wire->requestFrom(addr,1);
  if ((bool)received) {  //If received more than zero bytes
    wire->readBytes((uint8_t *) &readbuf, received);
    return(readbuf >> pin) & 0x01;
  }
  return received;
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
  //SPI serial interface (modes 0,0 and 1,1)ref https://ww1.microchip.com/downloads/en/devicedoc/21298e.pdf
  spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(SS, LOW);
  spi->transfer(this->writeBuffer, this->byteCount);
  // for(int i = 0; i < this->byteCount; i++) {
  //   spi->transfer(this->writeBuffer[i]);
  //   // delay(50);
  // }
  digitalWrite(SS, HIGH);
  spi->endTransaction();
}

void Blink::analogWrite(int pin, uint8_t value){
  if(pin==0)pin=1;
  int bytenum = (pin-1) / 8;
  int offset = (pin-1) % 8;
  int accumulator = 0;
  byte b = this->writeBuffer[bytenum];
  for(int i=0; i<max_brightness; i++){
    bool pinState = (i < value);
    bitWrite(b, pin, pinState);
    spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
    digitalWrite(SS, LOW);
    spi->transfer(b);
    // Serial.println(b,BIN);
    digitalWrite(SS, HIGH);
    spi->endTransaction();
  }
  // writebyte();
}
