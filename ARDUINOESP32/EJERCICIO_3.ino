// Pines
const int potPin = 34;       
const int buzzerPin = 13;    

// Variables
int potValue = 0;            
int frequency = 0;           
int pauseTime = 0;          

void setup() {
  pinMode(potPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  
  potValue = analogRead(potPin);

  
  frequency = map(potValue, 0, 4095, 200, 2000);  
  pauseTime = map(potValue, 0, 4095, 500, 50);    

  
  if (potValue >= 4000) {   
    tone(buzzerPin, frequency); 
  } else {
    
    tone(buzzerPin, frequency);
    delay(100);                // Tiempo que el buzzer está encendido
    noTone(buzzerPin);         // Apagar el buzzer
    delay(pauseTime);          // Pausa entre sonidos, ajustada según el potenciómetro
  }

}
