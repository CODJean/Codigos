#include <ESP32Servo.h>

int JOY_PIN = 26;          // Pin para el joystick
int BUTTON_PIN = 25;       // Pin para el botón
int SERVO_PIN = 13;        // Cambia a un pin PWM compatible
int LASER_PIN = 4;        // Pin para el láser

Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
  pinMode(LASER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200); // Para depuración
}

void loop() {
  int joystickValue = analogRead(JOY_PIN);
  int angle = map(joystickValue, 0, 4095, 0, 180);
  myServo.write(angle);

  // Debug: Imprime el valor de joystick y el ángulo mapeado
  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print(" - Angle: ");
  Serial.println(angle);

  if (digitalRead(BUTTON_PIN) == LOW)
  {
    digitalWrite(LASER_PIN, HIGH);
  } else {
    digitalWrite(LASER_PIN, LOW);
  }
  
  delay(15); // Pequeño retraso para estabilidad del servo
}

