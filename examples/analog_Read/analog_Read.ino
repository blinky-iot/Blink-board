#include "blink.h"

Blink adc;

void setup() {
	Serial.begin(115200);
  adc.begin();

void loop() {
  for(uint8_t p=0; p<8; p++){
    if(adc.analogRead(p)){
      Serial.print("Analog on GPIO #");
      Serial.print(p+1);
      Serial.println(" value -> "+String(adc.analogRead(p)));
    }
  }
	delay(10);
	}