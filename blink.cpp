#include "blink.h"

//uninitialised pointers to SPI objects
SPIClass *vspi = NULL;

Blink::Blink() {
  //initialise instance of the SPIClass attached to VSPI
  vspi = new SPIClass(VSPI);
  vspi->begin();
}

void Blink::blink_init_output(int num_output) {
  //set up slave select pins as outputs as the Arduino API
  //doesn't handle automatically pulling SS low
  pinMode(vspi->pinSS(), OUTPUT);
}
void Blink::write_spi_data(byte data) {
  vspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(vspi->pinSS(), LOW);  // Set the chip select pin LOW to start SPI communication
  //digitalWrite(SCK,LOW);
  vspi->transfer(data);  // Send the byte over SPI
  digitalWrite(vspi->pinSS(), HIGH);
  vspi->endTransaction();
}

void Blink::blink_init_input(int num_input){
  s
}
void Blink::blink_init_analog() {
  pinMode(analogss, OUTPUT);
  digitalWrite(analogss, HIGH);
}

uint16_t Blink::analogread(uint8_t channel) {
  uint8_t addr = 0b01100000 | ((channel & 0b111) << 2);
  // // SPI serial interface (modes 0,0 and 1,1)ref https://ww1.microchip.com/downloads/en/devicedoc/21298e.pdf
  vspi->beginTransaction(SPISettings(spianalogClk, MSBFIRST, SPI_MODE0));
    digitalWrite(analogss, LOW);         // Set the chip select pin LOW to start SPI communication
  vspi->transfer(addr);                  // Send the address byte over SPI
  uint8_t byte1 = vspi->transfer(0x00);  // Receive the first byte of data from SPI
  uint8_t byte2 = vspi->transfer(0x00);  // Receive the second byte of data from SPI
  digitalWrite(analogss, HIGH);          //set the chip select pin HIGH to end SPI communication
  return ((byte1 << 4) | (byte2 >> 4));
}