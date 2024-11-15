#define BUZZER_PIN 25
#define POT_PIN 34

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int delayTime = map(potValue, 0, 4095, 100, 1000);

  digitalWrite(BUZZER_PIN, HIGH);
  delay(delayTime);
  digitalWrite(BUZZER_PIN, LOW);
  delay(delayTime);
}
