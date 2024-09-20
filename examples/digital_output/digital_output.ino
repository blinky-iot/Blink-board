#include <blink.h>

Blink adc;

void setup() {
	Serial.begin(115200);
	adc.begin();
  adc.boardcount(1);
	}

void loop() {
  //  night rider
  for (int i = 1; i <= 8; i++)
  {
    adc.writeDigital(i,HIGH);
    // Serial.println("current pin "+String(i)+" is High");
    delay(100);
  }
  for (int i = 8; i >= 1; i--)
  {
    adc.writeDigital(i,LOW);
    // Serial.println("current pin "+String(i)+" is low");
    delay(100);
  }
	}