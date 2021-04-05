#include <ServoInput.h>
#define FOCUS 7 // pin for focus transistor
#define SHUTTER 6 // pin for shutter ransistor
ServoInputPin<2> servo; // pin 2 or 3 on pro mini
int pings = 25;    // when to send middle (focus) pos to prevent camera sleep
uint32_t idleTime;


void setup()
{
  pinMode(FOCUS, OUTPUT);
  pinMode(SHUTTER, OUTPUT);
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
  idleTime = millis();
  // Serial.begin(9600);
}

void loop(){
  float rcinput = servo.getPulse();
  int mode = map(rcinput, 1000, 2000, 0, 2);
  switch (mode){
     case 0:
      delay (50);
      if (millis() - idleTime > pings*1000) {
       digitalWrite(FOCUS, HIGH);
       digitalWrite(LED_BUILTIN, HIGH); 
       delay(100);
       digitalWrite(FOCUS, LOW);
       digitalWrite(LED_BUILTIN, LOW); 
       idleTime = millis();        
      }
      break;
     case 1:
       digitalWrite(FOCUS, HIGH);
       digitalWrite(LED_BUILTIN, HIGH); 
       delay(100);
       digitalWrite(FOCUS, LOW);
       digitalWrite(LED_BUILTIN, LOW); 
     case 2:
       digitalWrite(FOCUS, HIGH);
       delay(100);
       digitalWrite(SHUTTER, HIGH);
       digitalWrite(LED_BUILTIN, HIGH);
       delay(400);
       digitalWrite(SHUTTER, LOW);
       digitalWrite(FOCUS, LOW);        
       digitalWrite(LED_BUILTIN, LOW); 
       break;
   }
   // Serial.print(rcinput);
   // Serial.print(" - ");   
   // Serial.println(millis() - idleTime);
}
