#ifndef LEDCUSTOM_H
#define LEDCUSTOM_H

#include <Arduino.h>

class LedCustom {
public:
    LedCustom(int pin, String color, int defaultState);
    void turnOn();
    void turnOff();
private:
    int _pin;
    int _defaultState;
    String _color;
};

#endif