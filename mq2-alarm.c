/* Sample code for MQ2 Smoke Sensor Shield for pcDuino
   05/09/2013
**********************************************/
#include <core.h>

#define THRESHOLD 10

#define DIGITAL_PIN_SPEAKER 1
#define DIGITAL_PIN_BUTTON  6
#define ANALOG_PIN_MQ2      0

void playTone(int tone, int duration) {

  long i = 0;

  for (i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(DIGITAL_PIN_SPEAKER, HIGH);
    delayMicroseconds(tone);
    digitalWrite(DIGITAL_PIN_SPEAKER, LOW);
    delayMicroseconds(tone);
  }

}

void setup() {

  pinMode((DIGITAL_PIN_SPEAKER + 0), OUTPUT);
  pinMode((DIGITAL_PIN_SPEAKER + 1), OUTPUT);
  digitalWrite((DIGITAL_PIN_SPEAKER + 0), LOW);
  digitalWrite((DIGITAL_PIN_SPEAKER + 1), LOW);

  pinMode((DIGITAL_PIN_BUTTON), INPUT);

}

void loop() {

  int sensorValue = 0;
  static int silenced = 0;

  printf("silenced = %d\n", silenced);

  sensorValue = analogRead(ANALOG_PIN_MQ2);
  printf("smoke = %d\n", sensorValue);

  if(sensorValue > THRESHOLD) {
    printf("ALARM!\n");


    if (silenced == 0) {
      if (digitalRead(DIGITAL_PIN_BUTTON) == 1) {
	silenced = 1;
      }
      playTone(1136, 100);
    }
    else {
      delay(100);
    }


  }
  else {
    silenced = 0;
    delay(100);
  }

}
