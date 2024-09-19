#ifndef BLINK_H
#define BLINK_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#define PCF8574_I2CADDR1_DEFAULT 0x3E ///< PCF8574 default I2C address
#define PCF8574_I2CADDR2_DEFAULT 0x3F ///< PCF8574 default I2C address

class Blink {
	public:
		Blink(SPIClass &spi = SPI, TwoWire &wire = Wire);//, TwoWire *wire = &Wire);
    ~Blink();
		void begin();
    void gsm_begin();
    bool isConnected();
    char* wirescan();
		uint16_t analogRead(uint8_t channel);
    void boardcount(int board);
    void writeDigital(int pin, bool value);
    void writeDigital(int pin, int board,bool value);
    void pwm_start(uint32_t frequency);
    void set_pwm(int pin,unsigned int value);
    bool digitalRead(uint8_t pin,uint8_t addr);
    bool digitalRead(uint8_t pin);

	private:
		SPIClass *spi;
    TwoWire *wire;
    // hw_timer_t *timer = NULL;

		uint8_t cs =27;
    uint8_t ss =5;
    uint8_t Ethernet_cs = 2;
    uint8_t Ethernet_rst = 4;
    uint8_t Sim_pwrkey = 33;
    static const int spiClk = 1000000;  // 1 MHz
    /*time between the end of the sample
    period and the time that all 12 data bits have been
    clocked out must not exceed 1.2 ms (effective clock
    frequency of 10 kHz)*/
    static const int spianalogClk = 10000;
    uint8_t readbuf = 0;
    int bitCount;
    int byteCount;
    byte writeBuffer[16];
    char _address[255];
    void writebyte();
    // void InitTimer(uint32_t frequency);
  public:
    unsigned char * m_PWMValues;
	};

#endif
