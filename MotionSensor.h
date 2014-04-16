#include "Arduino.h"

class MotionSensor {
  public:
    MotionSensor(
      int sensor,
      int id,
      int redLED,
      int greenLED,
      String path = "http://10.0.1.5/update"
    );
    void pulse();
    int id;
    static int waitTime;

  private:
    int _status;
    int _sensor;
    int _red;
    int _green;
    bool _notified;
    int _lastNotification;
    unsigned long _timeSet;
    String _path;
    bool hasChanged();
    void notify();
};

