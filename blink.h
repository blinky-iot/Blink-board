#ifndef Blink_h
#define Blink_h
#include <Arduino.h>
#include <SPI.h>
#include <wire.h>

#define PCF8574_INITIAL_ADDR 0x3E

#define analogss 27
#define VSPI

static const int spiClk = 1000000;  // 1 MHz
/*time between the end of the sample
period and the time that all 12 data bits have been
clocked out must not exceed 1.2 ms (effective clock
frequency of 10 kHz)*/
static const int spianalogClk = 10000;

class Blink {
  public:
  Blink();
  void blink_init_output(int num_output);
  void blink_init_input(int num_input);
  void blink_init_analog();
  uint8_t digitalRead(uint8_t channel);
  uint16_t analogread(uint8_t channel);
  void write_spi_data(byte data);
  void switch_output();
  private:
};

#endif