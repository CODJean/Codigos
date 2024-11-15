// #define POT_PIN 27
// int pin1 = 2;
// int pin2 = 4;
// int pin3 = 5;
// int pin4 = 26;
// int pin5 = 25;
// int pin6 = 33;

// void setup() {
//   pinMode(POT_PIN,INPUT);
//   Serial.begin(115200);
//   pinMode(pin1,OUTPUT);
//   pinMode(pin2,OUTPUT);
//   pinMode(pin3,OUTPUT);
//   pinMode(pin4,OUTPUT);
//   pinMode(pin5,OUTPUT);
//   pinMode(pin6,OUTPUT);
// }

// void loop() {
//   int potValue = analogRead(POT_PIN);
//   int numLeds = map(potValue, 0, 4095, 0, 6);
//   if (numLeds==1){
//     digitalWrite(pin1, HIGH);
//   }else if  (numLeds==2){
//     digitalWrite(pin1, HIGH);
//     digitalWrite(pin2, HIGH);
//   }else if  (numLeds==3){
//     digitalWrite(pin1, HIGH);
//     digitalWrite(pin2, HIGH);
//     digitalWrite(pin3, HIGH);
//   }else if (numLeds==4){
//     digitalWrite(pin1, HIGH);
//     digitalWrite(pin2, HIGH);
//     digitalWrite(pin3, HIGH);
//     digitalWrite(pin4, HIGH);
//   }else if  (numLeds==5){
//     digitalWrite(pin1, HIGH);
//     digitalWrite(pin2, HIGH);
//     digitalWrite(pin3, HIGH);
//     digitalWrite(pin4, HIGH);
//     digitalWrite(pin5, HIGH);
//   }else if  (numLeds==6){
//     digitalWrite(pin1, HIGH);
//     digitalWrite(pin2, HIGH);
//     digitalWrite(pin3, HIGH);
//     digitalWrite(pin4, HIGH);
//     digitalWrite(pin5, HIGH);
//     digitalWrite(pin6, HIGH);
//   }else {
//     digitalWrite(pin1, 0);
//     digitalWrite(pin2, 0);
//     digitalWrite(pin3, 0);
//     digitalWrite(pin4, 0);
//     digitalWrite(pin5, 0);
//     digitalWrite(pin6, LOW);
//   }
//   Serial.println(numLeds);
//   //Serial.println(potValue);

// }
#define POT_PIN 27
const int pin1 = 2;
const int pin2 = 4;
const int pin3 = 5;
const int pin4 = 26;
const int pin5 = 25;
const int pin6 = 33;

void setup() {
  pinMode(POT_PIN, INPUT);
  Serial.begin(115200);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int numLeds = map(potValue, 0, 4095, 0, 6);

  // Encender LEDs de acuerdo al valor de numLeds
  digitalWrite(pin1, numLeds >= 1 ? HIGH : LOW);
  digitalWrite(pin2, numLeds >= 2 ? HIGH : LOW);
  digitalWrite(pin3, numLeds >= 3 ? HIGH : LOW);
  digitalWrite(pin4, numLeds >= 4 ? HIGH : LOW);
  digitalWrite(pin5, numLeds >= 5 ? HIGH : LOW);
  digitalWrite(pin6, numLeds >= 6 ? HIGH : LOW);

  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" - Num LEDs: ");
  Serial.println(numLeds);

  delay(10);  // Pequeña pausa para estabilidad
}

