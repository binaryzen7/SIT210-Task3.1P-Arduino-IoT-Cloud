#include "thingProperties.h"
int outputpin=A0;

void setup() {
  // Initialize serial and wait for port to open:
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  // The delay gives the time to wait for the Serial Monitor without blocking if it is absent
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  int analogValue=analogRead(outputpin);
  float millivolts=(analogValue/1024.0)*3300;
  float celsius=millivolts/10;
  temperature=celsius;
   
}


