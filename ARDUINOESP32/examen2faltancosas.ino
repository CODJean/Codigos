// Definición de pines
const int trigPin = 9;
const int echoPin = 10;

// Constantes del tanque
const float alturaTotal = 106.68; // cm (1.0668 m)
const float diametro = 20.0; // cm (2 m / 10)
const float distanciaSensorBorde = 6.6; // cm

// Variables
float distancia = 0;
float volumen = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Medir distancia
  distancia = medirDistancia();
  
  // Calcular volumen
  volumen = calcularVolumen(distancia);
  
  // Imprimir resultados
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  Serial.print("Volumen: ");
  Serial.print(volumen);
  Serial.println(" m3");
  
  // Simular subida al cloud
  simularSubidaCloud(volumen);
  
  delay(5000); // Esperar 5 segundos antes de la siguiente medición
}

float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

float calcularVolumen(float distanciaMedida) {
  float alturaLiquido = alturaTotal - distanciaSensorBorde - distanciaMedida;
  if (alturaLiquido < 0) alturaLiquido = 0;
  float radio = diametro / 2;
  return PI * radio * radio * alturaLiquido / 1000000; // Convertir cm3 a m3
}

void simularSubidaCloud(float volumen) {
  Serial.println("Simulando subida al cloud...");
  Serial.print("Volumen enviado: ");
  Serial.print(volumen);
  Serial.println(" m3");
  Serial.println("Datos enviados con éxito.");
  Serial.println();
}
