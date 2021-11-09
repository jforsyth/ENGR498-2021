/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  USBDevice.attach();
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  while(Serial.available()>0)
  {
	  char c = Serial.read();
	  Serial.print(c);
  }
}
