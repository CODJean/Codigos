const int buzzerPin = 4;

void setup() {
  // Configurar el pin del buzzer como salida
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Encender el buzzer (patrón 1)
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(buzzerPin, LOW);
  delay(500); 

  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(buzzerPin, LOW);
  delay(50); 
 
   digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(100); 
}
