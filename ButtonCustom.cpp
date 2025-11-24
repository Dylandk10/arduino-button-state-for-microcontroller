#include "ButtonCustom.h"

ButtonCustom::ButtonCustom(int pin, int ledPin, bool isLightOn) {
    _pin = pin;
    _ledPin = ledPin;
    _isLightOn = isLightOn;
    _lastButtonState = HIGH; // set to high because we want it to start off
    pinMode(pin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

bool ButtonCustom::isPressed() {
    static unsigned long lastPressTime = 0;
    unsigned long now = millis();

    // Button is LOW when pressed with INPUT_PULLUP
    if (digitalRead(_pin) == LOW) {
        if (now - lastPressTime > 200) { // 200ms debounce
            lastPressTime = now;
            return true;   // Valid press
        }
    }

    return false;
}

bool ButtonCustom::wasReleased() {
    bool currentState = digitalRead(_pin);  // HIGH or LOW
    bool event = false;

    // Detect transition: LOW → HIGH (button released)
    if (_lastButtonState == LOW && currentState == HIGH) {
        event = true;
    }

    _lastButtonState = currentState;
    return event;
}

void ButtonCustom::checkIsPressed() {
    if (wasReleased()) {
        _isLightOn = !_isLightOn;
    }
    setLightOnOrOff();
}

void ButtonCustom::setLightOnOrOff() {
    if(_isLightOn) {
        digitalWrite(_ledPin, HIGH);
    } else {
        digitalWrite(_ledPin, LOW);
    }
}