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
		uint16_t analogRead(uint8_t channel);
    void boardcount(int board);
    void writeDigital(int bitnum, bool value);
    void writeDigital(int pin, int board,bool value);
    void pwm_start(uint32_t frequency);
    void set_pwm(int pin,unsigned int value);
    // void digitalWrite(uint8_t pinnum, bool val);
    bool digitalRead(uint8_t pin);
    bool isConnected();

	private:
		SPIClass *spi;
    TwoWire *wire;
    hw_timer_t *timer = NULL;

		uint8_t cs =27;
    uint8_t ss =5;
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
    void writebyte();
    void InitTimer(uint32_t frequency);
  public:
    unsigned char * m_PWMValues;
	};

#endif
