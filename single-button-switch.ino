#include "ButtonCustom.h"

int ledPin = 6;
int buttonPin = 4;

ButtonCustom mainButton(buttonPin, ledPin, false);

void setup() {

}

void loop() {
  mainButton.checkIsPressed();

}
