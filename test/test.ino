#include "blink.h"
Blink adc;

void setup() {
	Serial.begin(115200);
  
  adc.begin();
  adc.boardcount(1);
  Serial.println("testing");
  adc.gsm_begin();
  Serial.println(adc.wirescan());
  Serial.println(adc.isConnected());
  adc.writeDigital(1,0,HIGH);
  // adc.set_pwm(8, LOW);
  // adc.analogWrite(6,128);
  Serial.println("end");
	}

void loop() {
  for(uint8_t p=0; p<8; p++){
    if(adc.analogRead(p)){
      Serial.print("Analog on GPIO #");
      Serial.print(p+1);
      Serial.println(" value -> "+String(adc.analogRead(p)));
    }
  }
	delay(10); 
  // for (uint8_t p=1; p<8; p++) {
  //   if (adc.digitalRead(p)) {
  //     Serial.print("Button on GPIO #");
  //     Serial.print(p+1);
  //     Serial.println(" pressed!");
  //   }}
  //   delay(10); 
    for (uint8_t p=0; p<8; p++) {
    if (adc.digitalRead(p,0x3E)) {
      Serial.print("Button on 0x3F GPIO #");
      Serial.print(p+1);
      Serial.println(" pressed!");
    }}
    delay(10); 
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
