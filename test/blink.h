#include <stdint.h>
#ifndef BLINK_H
#define BLINK_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#define PCF8574_I2CADDR1_DEFAULT 0x3E ///< PCF8574 default I2C address
#define PCF8574_I2CADDR2_DEFAULT 0x3F ///< PCF8574 default I2C address
// #define SPI_ETHERNET_SETTINGS SPISettings(14000000, MSBFIRST, SPI_MODE0)

class Blink {
	public:
		Blink(SPIClass &spi = SPI, TwoWire &wire = Wire);//, TwoWire *wire = &Wire);
    ~Blink();
		void begin();
    void gsm_begin();
		uint16_t analogRead(uint8_t channel);
    void boardcount(int board);
    void writeDigital(int bitnum, bool value);
    void analogWrite(int pin, uint8_t value);
    void writeDigital(int pin, int board,bool value);
    bool digitalRead(uint8_t pin,uint8_t addr);
    bool digitalRead(uint8_t pin);
    bool isConnected();
    char* wirescan();

	private:
		SPIClass *spi;
    TwoWire *wire;

		uint8_t cs =27;
    uint8_t ss =5;
    uint8_t Ethernet_cs = 2;
    uint8_t Ethernet_rst = 4;
    uint8_t Sim_pwrkey = 33;
    uint8_t max_brightness = 255;
    static const int spiClk = 1000000;  // 1 MHz
    /*time between the end of the sample
    period and the time that all 12 data bits have been
    clocked out must not exceed 1.2 ms (effective clock
    frequency of 10 kHz)*/
    static const int spianalogClk = 10000;
    uint8_t readbuf;
    int bitCount;
    int byteCount;
    uint8_t writeBuffer[16] = {0};
    void writebyte();  
    char _address[255];
  public:
    unsigned char * m_PWMValues;
	};

#endif
