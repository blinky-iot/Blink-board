#include <blink.h>

Blink adc;

void setup() {
	Serial.begin(115200);
  adc.begin();
  Serial.println("testing");
	}

void loop() {
  for (uint8_t p=0; p<8; p++) {
    if (adc.digitalRead(p)) {
      Serial.print("Button on GPIO #");
      Serial.print(p+1);
      Serial.println(" pressed!");
    }}
    delay(10); 
    for (uint8_t p=0; p<8; p++) {
    if (adc.digitalRead(p,0x3F)) {
      Serial.print("Button on 0x3F GPIO #");
      Serial.print(p+1);
      Serial.println(" pressed!");
    }}
    delay(10); 
	}
