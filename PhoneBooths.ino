#include <Bridge.h>
#include "MotionSensor.h"

MotionSensor pb1(2, 1);
MotionSensor pb2(4, 2);

void setup() {
  Serial.begin(9600);

  // Bridge startup
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Bridge.begin();
  digitalWrite(13, LOW);
}

void loop() {
  pb1.pulse();
  pb2.pulse();
}
