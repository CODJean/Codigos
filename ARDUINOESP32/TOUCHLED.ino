/*

This is an example how to use Touch Intrrerupts
The sketch will tell when it is touched and then released as like a push-button

This method based on touchInterruptSetThresholdDirection() is only available for ESP32
*/

#include "Arduino.h"

int threshold = 20;
bool touchActive = false;
bool lastTouchActive = false;
bool testingLower = true;

void gotTouchEvent() {
  if (lastTouchActive != testingLower) {
    touchActive = !touchActive;
    testingLower = !testingLower;
    // Touch ISR will be inverted: Lower <--> Higher than the Threshold after ISR event is noticed
    touchInterruptSetThresholdDirection(testingLower);
  }
}

void setup() {
  pinMode(21,OUTPUT);
  delay(1000);  // give me time to bring up serial monitor
  touchAttachInterrupt(4, gotTouchEvent, threshold);
  // Touch ISR will be activated when touchRead is lower than the Threshold
  touchInterruptSetThresholdDirection(testingLower);
}

void loop() {
  if (lastTouchActive != touchActive) {
    lastTouchActive = touchActive;
    if (touchActive) {
      digitalWrite(21,HIGH);
    } else {
      digitalWrite(21,LOW);
    }
  }
}
