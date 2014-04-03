#include "Arduino.h"

class MotionSensor {
  public:
    MotionSensor(int sensor, int id, String path = "http://10.0.1.8");
    void pulse();
    int id;

  private:
    int _status;
    int _sensor;
    bool _notified;
    int _lastNotification;
    unsigned long _timeSet;
    String _path;
    bool hasChanged();
    void notify();
};
