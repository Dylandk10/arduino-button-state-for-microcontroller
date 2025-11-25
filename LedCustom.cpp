#include "LedCustom.h"

LedCustom::LedCustom(int pin, String color, int defaultState) {
    _pin = pin;
    _color = color;
    _defaultState = defaultState; // HIGH OR LOW
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _defaultState);
}

void LedCustom::turnOn() {
  digitalWrite(_pin, HIGH);
}

void LedCustom::turnOff() {
  digitalWrite(_pin, LOW);
}

