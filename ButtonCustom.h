#ifndef BUTTONCUSTOM_H
#define BUTTONCUSTOM_H

#include <Arduino.h>

class ButtonCustom {
public:
    ButtonCustom(int pin, int ledPin, bool isLightOn);
    bool isPressed();
    void checkIsPressed();
    void setLightOnOrOff();
    bool wasReleased();

private:
    int _pin;
    int _ledPin;
    bool _isLightOn;
    int _lastButtonState;
};

#endif
