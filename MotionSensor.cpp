#include "MotionSensor.h"
#include <HttpClient.h>

MotionSensor::MotionSensor(int sensor, int id, String path) {
  MotionSensor::id = id;
  _sensor = sensor;
  _status = 0;
  _path = path;
  _notified = false;
}

void MotionSensor::pulse() {
  if (hasChanged()) {
    if (_status == HIGH) {
      notify();
    } else {
      _notified = false;
      _timeSet = millis();
    }
  }
  
  if (!_notified && (millis() - _timeSet > 1000*1)) {
    notify();
  }
}

void MotionSensor::notify() {
  _notified = true;
  if (_lastNotification == _status) {
    return;
  }
  _lastNotification = _status;

  HttpClient client;
  client.get(_path + "/" + id + "/" + _status);

  Serial.flush();
}

bool MotionSensor::hasChanged() {
  int lastStatus = _status;
  _status = digitalRead(_sensor);

  return (_status != lastStatus);
}
