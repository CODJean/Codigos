#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
#define BUTTON_PIN 5
#define DEBUTTON_PIN 18
#define REBUTTON_PIN 19
int count = 0;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {15, 2, 0, 4}; // Pines de cada dígito
  byte segmentPins[] = {13, 12, 14, 27, 26, 25, 33}; // Pines de cada segmento (a-g)
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(DEBUTTON_PIN, INPUT_PULLUP);
  pinMode(REBUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  int rebuttonState = digitalRead(REBUTTON_PIN);
  int debuttonState = digitalRead(DEBUTTON_PIN);
  // Verificar si el botón fue presionado
  if (buttonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) >debounceDelay) {
    lastDebounceTime = millis();
    count = (count + 1) % 10000; // Incrementar y reiniciar el contador al llegar a 9999
  }
  lastButtonState = buttonState;
  // Verificar si el botón fue presionado
  if (debuttonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) >debounceDelay) {
    lastDebounceTime = millis();
    count = (count - 1) % 10000; // Incrementar y reiniciar el contador al llegar a 9999
  }
  lastButtonState = debuttonState;
    lastButtonState = buttonState;
  // Verificar si el botón fue presionado
  if (rebuttonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) >debounceDelay) {
    lastDebounceTime = millis();
    count = 0; // Incrementar y reiniciar el contador al llegar a 9999
  }
  lastButtonState = debuttonState;
  sevseg.setNumber(count); // Configura el número que se mostrará en el display
  sevseg.refreshDisplay(); // Must run repeatedly
}

