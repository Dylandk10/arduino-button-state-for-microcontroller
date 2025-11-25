#include "LedHandler.h"
#include "LedCustom.h"

LedHandler::LedHandler(LedCustom* leds, int len) {
  _leds = leds;
  _maxLen = len; //can not be 0
  _currentIndex = 0;
  _lastIndex = 0;
}

void LedHandler::moveToNextLight() {
  _lastIndex = _currentIndex;
  _currentIndex = (_currentIndex + 1) > _maxLen ? 0 : _currentIndex + 1;
  lightUp();
}

void LedHandler::lightUp() {
  _leds[_lastIndex].turnOff();
  _leds[_currentIndex].turnOn();
}