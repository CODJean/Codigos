#define BUTTON_PIN 5
#define BUZZER_PIN 32

void setup() {
 // put your setup code here, to run once:
 pinMode(BUZZER_PIN, OUTPUT);
 pinMode(BUTTON_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  int pedro = digitalRead(BUTTON_PIN);
  if (pedro == LOW){
    digitalWrite(BUZZER_PIN, 1);
  }else{
    digitalWrite(BUZZER_PIN, 0);
  }
  delay(100);
}
