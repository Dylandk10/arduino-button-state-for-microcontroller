#include "ButtonCustom.h"
#include "LedCustom.h"
#include "LedHandler.h"

int ledPin3 = 3;
int ledPin6 = 6;
int ledPin9 = 9;
int buttonPin = 4;

LedCustom leds[] = {
  LedCustom(ledPin3, "Blue", HIGH),
  LedCustom(ledPin6, "Yellow", LOW),
  LedCustom(ledPin9, "Red", LOW)
};

LedHandler ledsHandler(leds, 2);
ButtonCustom mainButton(buttonPin, &ledsHandler);


void setup() {

}

void loop() {
  mainButton.checkIsPressed();

}
