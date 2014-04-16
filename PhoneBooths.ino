#include <Bridge.h>
#include "MotionSensor.h"

int MotionSensor::waitTime = 5;

// Order: Sensor Pin, Remote ID, Red LED, Green LED, http path
MotionSensor pb1(2, 1, 3, 4);
MotionSensor pb2(8, 2, 9, 10);

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Bridge.begin();
  digitalWrite(13, LOW);
}

void loop() {
  pb1.pulse();
  pb2.pulse();
  delay(10);
}

