#include <SevSeg.h>

SevSeg sevseg;  // Objeto de la biblioteca SevSeg
int counter = 0;  // Inicializa el contador

// Pines de los pulsadores
const int incrementPin = 25;  // Pin para el pulsador de incremento
const int resetPin = 26;      // Pin para el pulsador de reset

void setup() {
  // Configuración de los pines de los pulsadores
  pinMode(incrementPin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);

  // Configuración del display
  byte numDigits = 4;
  byte digitPins[] = {23, 22, 21, 19};  // Pines de los dígitos del display (D1, D2, D3, D4)
  byte segmentPins[] = {15, 2, 4, 16, 17, 5, 18, 19};  // Pines de los segmentos (A, B, C, D, E, F, G, DP)
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);  // Cambiar a COMMON_ANODE si es de ánodo común
  sevseg.setBrightness(90);  // Ajusta el brillo del display
}

void loop() {
  // Lee el estado de los pulsadores
  bool incrementPressed = digitalRead(incrementPin) == LOW;
  bool resetPressed = digitalRead(resetPin) == LOW;

  // Incrementa el contador si se presiona el pulsador de incremento
  if (incrementPressed) {
    counter++;
    if (counter > 9999) {
      counter = 0;  // Reinicia a 0 si se excede 9999
    }
    delay(200);  // Retraso para evitar múltiples incrementos con una sola pulsación
  }

  // Reinicia el contador si se presiona el pulsador de reset
  if (resetPressed) {
    counter = 0;
    delay(200);  // Retraso para evitar múltiples reinicios con una sola pulsación
  }

  // Muestra el valor del contador en el display
  sevseg.setNumber(counter);
  sevseg.refreshDisplay();  // Actualiza el display
}

