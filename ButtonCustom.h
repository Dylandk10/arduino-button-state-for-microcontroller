#ifndef BUTTONCUSTOM_H
#define BUTTONCUSTOM_H

#include <Arduino.h>
#include "LedHandler.h"


class ButtonCustom {
public:
    ButtonCustom(int pin, LedHandler* ledHandler);
    bool isPressed();
    void checkIsPressed();
    void moveLight();
    bool wasReleased();

private:
    int _pin;
    bool _isClicked;
    int _lastButtonState;
    LedHandler* _ledHandler;
};

#endif
