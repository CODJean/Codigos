#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <TinyGPS++.h>
#include <WiFi.h>
#include <UniversalTelegramBot.h>
#include <Adafruit_VL53L0X.h>

// Pines de sensores y actuadores
const int TRIG[4] = {32, 33, 25, 26}; // Pines trig de los sensores ultrasónicos
const int ECHO[4] = {27, 14, 12, 13}; // Pines echo de los sensores ultrasónicos
const int VOLT_PIN = 34;              // Pin para medir el voltaje de la batería
const int BOMBA_PIN = 4;              // Pin para activar la bomba
const int CEPILLO_PIN = 5;            // Pin para activar el motor de cepillos

// Pines del puente H
const int ENA = 18;  // Control de velocidad del motor izquierdo
const int IN1 = 19;  // Motor izquierdo - Dirección 1
const int IN2 = 23;  // Motor izquierdo - Dirección 2
const int ENB = 16;  // Control de velocidad del motor derecho
const int IN3 = 17;  // Motor derecho - Dirección 1
const int IN4 = 21;  // Motor derecho - Dirección 2

// Configuración del sistema
const int UMBRAL_OBSTACULO = 30; // Distancia en cm para esquivar obstáculos
const int VOLT_UMBRAL = 1050;    // Umbral mínimo de batería en mV

// GPS y Telegram
TinyGPSPlus gps;
HardwareSerial GPS(1);
WiFiClient client;
UniversalTelegramBot bot("<TOKEN>", client);

Adafruit_MPU6050 mpu;
Adafruit_VL53L0X lox;

// WiFi
const char* ssid = "PERRO";
const char* password = "Jr123456789";

// Variables de estado
bool tarea_iniciada = false;
bool recargando = false;

// Variables de gps
double homeLatitude = 0.0;
double homeLongitude = 0.0;

// Funciones de control de motores
void avanzar() {
  analogWrite(ENA, 205);  // Velocidad motor izquierdo (5% de 4095)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 205);  // Velocidad motor derecho (5% de 4095)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarIzquierda() {
  analogWrite(ENA, 205);  // Velocidad motor izquierdo (5% de 4095)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 205);  // Velocidad motor derecho (5% de 4095)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarDerecha() {
  analogWrite(ENA, 205);  // Velocidad motor izquierdo (5% de 4095)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 205);  // Velocidad motor derecho (5% de 4095)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void detener() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Función para medir distancia con un sensor ultrasónico
int medirDistancia(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH);
  return duracion * 0.034 / 2;  // Convertir a cm
}

// Función para medir la distancia con el sensor LIDAR VL53L0X
float medirDistanciaLIDAR() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {           // Si el rango es válido
    return measure.RangeMilliMeter / 10.0;  // Convertir de mm a cm
  } else {
    return -1.0;  // Error al medir
  }
}

// Lógica para esquivar obstáculos
void esquivarObstaculo() {
  detener();
  delay(500);

  int distIzq = medirDistancia(TRIG[0], ECHO[0]);
  int distDer = medirDistancia(TRIG[1], ECHO[1]);

  if (distIzq > UMBRAL_OBSTACULO && distDer <= UMBRAL_OBSTACULO) {
    enviarNotificacion("Espacio detectado a la izquierda. Girando.");
    girarIzquierda();
    delay(1000);  // Ajusta para un giro de 90 grados
    avanzar();
    delay(500);   // Avanza un poco para evitar el obstáculo
  } else if (distDer > UMBRAL_OBSTACULO && distIzq <= UMBRAL_OBSTACULO) {
    enviarNotificacion("Espacio detectado a la derecha. Girando.");
    girarDerecha();
    delay(1000);  // Ajusta para un giro de 90 grados
    avanzar();
    delay(500);
  } else {
    enviarNotificacion("Espacio no detectado. Girando hacia el lado más seguro.");
    if (distIzq > distDer) {
      girarIzquierda();
    } else {
      girarDerecha();
    }
    delay(1000);
    avanzar();
    delay(500);
  }

  // Retomar la posición inicial
  girarDerecha();
  delay(1000); // Ajusta para regresar a la posición inicial
}

// Funciones de Telegram y otras configuraciones omitidas para brevedad

void loop() {
  // Leer distancias de los sensores ultrasónicos y el LIDAR
  int distFrente = medirDistancia(TRIG[2], ECHO[2]);
  float distLidar = medirDistanciaLIDAR();

  if (distFrente < UMBRAL_OBSTACULO || (distLidar != -1.0 && distLidar < UMBRAL_OBSTACULO)) {
    enviarNotificacion("Obstáculo detectado al frente. Esquivando.");
    esquivarObstaculo();
  } else {
    avanzar();
  }

  delay(100);
}
