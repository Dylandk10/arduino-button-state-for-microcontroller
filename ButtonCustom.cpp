#include "ButtonCustom.h"
#include "LedHandler.h"

ButtonCustom::ButtonCustom(int pin, LedHandler* ledHandler) {
    _pin = pin;
    _ledHandler = ledHandler;
    _lastButtonState = HIGH; // set to high because we want it to start off
    _isClicked = false;
    pinMode(pin, INPUT_PULLUP);
}

//check if button is pressed with debounce
// debounce is probably not needed right now as we are checking on release but keep it for now
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
    if (wasReleased() && !isPressed()) {
        _isClicked = !_isClicked;
        moveLight();
    }
}

void ButtonCustom::moveLight() {
    _ledHandler->moveToNextLight();
}