#ifndef LEDHANDLER_H
#define LEDHANDLER_H

#include <Arduino.h>
#include "LedCustom.h"

class LedHandler {
public:
    LedHandler(LedCustom* leds, int len);
    void moveToNextLight();
    void lightUp();
private:
  LedCustom* _leds;
  int _maxLen;
  int _currentIndex;
  int _lastIndex;
};

#endif