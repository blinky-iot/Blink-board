#include "blink.h"
hw_timer_t *timer = NULL;
Blink adc;

// use 12 bit precision for LEDC timer
#define LEDC_TIMER_12_BIT 12

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ 5000

// fade LED PIN (replace with LED_BUILTIN constant for built-in LED)
#define LED_PIN 15

// define starting duty, target duty and maximum fade time
#define LEDC_START_DUTY  (0)
#define LEDC_TARGET_DUTY (4095)
#define LEDC_FADE_TIME   (3000)

bool fade_ended = false;  // status of LED fade
bool fade_on = true;
#define LED 15 
void IRAM_ATTR LED_FADE_ISR() {
  adc.analogWrite(6,10);
  digitalWrite(LED, !digitalRead(LED));
}

void init_timer(){
  timer = timerBegin(LEDC_BASE_FREQ);
  timerAttachInterrupt(timer, &LED_FADE_ISR);
  // Set alarm to call onTimer function every second (value in microseconds).
  // Repeat the alarm (third parameter) with unlimited count = 0 (fourth parameter).
  timerAlarm(timer, (256/200), true, 0);
}
void setup() {
	Serial.begin(115200);
  
  pinMode(LED,OUTPUT);
  adc.begin();
  adc.boardcount(1);
  Serial.println("testing");
  adc.gsm_begin();
  // Serial.println(adc.isConnected());
  Serial.println(adc.wirescan());
  init_timer();
  // adc.writeDigital(1,0,HIGH);
  // adc.set_pwm(8, LOW);
  // adc.analogWrite(6,128);
  Serial.println("end");
	}

void loop() {
  // for(uint8_t p=0; p<8; p++){
  //   if(adc.analogRead(p)){
  //     Serial.print("Analog on GPIO #");
  //     Serial.print(p+1);
  //     Serial.println(" value -> "+String(adc.analogRead(p)));
  //   }
  // }
	// delay(10); 
  // for (uint8_t p=0; p<8; p++) {
  //   if (adc.digitalRead(p)) {
  //     Serial.print("Button on GPIO #");
  //     Serial.print(p+1);
  //     Serial.println(" pressed!");
  //   }}
  //   delay(10); 
  //   for (uint8_t p=0; p<8; p++) {
  //   if (adc.digitalRead(p,0x3F)) {
  //     Serial.print("Button on 0x3F GPIO #");
  //     Serial.print(p+1);
  //     Serial.println(" pressed!");
  //   }}
  //   delay(10); 
  // //  night rider
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
