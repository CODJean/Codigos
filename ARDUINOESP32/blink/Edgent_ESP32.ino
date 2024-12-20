#define BLYNK_TEMPLATE_ID "TMPL2J4DIrFXS"
#define BLYNK_TEMPLATE_NAME "led test"

#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_ESP32_DEV_MODULE
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI

#include "BlynkEdgent.h"

const byte ledPin = 2;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(ledPin, OUTPUT);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}

BLYNK_WRITE(V1) {
  int state = param.asINT();
  digitalWrite(ledPin,state) 
}
