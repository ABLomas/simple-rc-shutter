#include <ServoInput.h>
#define FOCUS 6
#define SHUTTER 7
ServoInputPin<2> servo; // can also be pin 3 on pro mini

void setup()
{
  pinMode(FOCUS, OUTPUT);
  pinMode(SHUTTER, OUTPUT);
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
}

void loop(){
  float rcinput = servo.getPulse();
  int mode = map(rcinput, 1000, 2000, 0, 2);
  switch (mode){
     case 0:
      delay (50);
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
}
