/* Sample code for MQ2 Smoke Sensor Shield for pcDuino
   05/09/2013
**********************************************/
#include <core.h>

const int analogInPin = 0;

void setup() {
    // No Digital Pins to Setup
}

void loop() {

  int sensorValue = analogRead(analogInPin);
  printf("sensor = %d\n", sensorValue);
  delay(100);

}
