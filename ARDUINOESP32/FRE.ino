const int pulsePin = 34;  // Pin donde se conecta la señal de pulso
volatile unsigned long pulseCount = 0;  // Contador de pulsos (volatile para interrupciones)
unsigned long lastTime = 0;  // Última vez que se calculó la frecuencia
float frequency = 0.0;  // Frecuencia calculada

// Para el debounce
unsigned long lastDebounceTime = 0;  // Tiempo de la última transición válida
unsigned long debounceDelay = 50;    // Tiempo para debouncing (50ms)

void countPulse() {
  // Verificar si ha pasado el tiempo necesario para el debounce
  unsigned long currentTime = millis();
  if (currentTime - lastDebounceTime > debounceDelay) {
    pulseCount++;  // Cuenta un solo pulso
    lastDebounceTime = currentTime;  // Actualiza el tiempo del debounce
  }
}

void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serial
  pinMode(pulsePin, INPUT);  // Configura el pin de pulso como entrada
  attachInterrupt(digitalPinToInterrupt(pulsePin), countPulse, RISING);  // Configura la interrupción para detectar flanco ascendente (RISING)
}

void loop() {
  // Cada segundo, calcula la frecuencia y reinicia el contador
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= 1000) {
    frequency = pulseCount;  // La frecuencia es el número de pulsos por segundo
    Serial.print("Frecuencia: ");
    Serial.print(frequency);
    Serial.println(" pulsos por segundo");
    pulseCount = 0;  // Reinicia el contador de pulsos
    lastTime = currentTime;  // Actualiza el tiempo
  }
}

