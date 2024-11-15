#define RED_PIN 19
#define GREEN_PIN 18
#define BLUE_PIN 5
#define POT_RED 25
#define POT_GREEN 26
#define POT_BLUE 27

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(POT_BLUE,INPUT);
  pinMode(POT_GREEN,INPUT);
  pinMode(POT_RED,INPUT);
  Serial.begin(115200);

}

void loop() {
  // Lee los valores de los potenciómetros y mapea el rango de 0-4095 a 0-255
  int redValue = map(analogRead(POT_RED), 0, 4095, 0, 255);
  int greenValue = map(analogRead(POT_GREEN), 0, 4095, 0, 255);
  int blueValue = map(analogRead(POT_BLUE), 0, 4095, 0, 255);
  Serial.println(POT_BLUE);
  Serial.println(POT_GREEN);
  Serial.println(POT_RED);
  Serial.println(redValue);
  Serial.println(greenValue);
  Serial.println(blueValue);

  // Aplica los valores mapeados a los pines del LED RGB
  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);

  delay(10); // Pequeña pausa para suavizar el cambio de color
}
