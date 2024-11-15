const int pulsador = 19;
volatile int contador = 0;
const unsigned long intervalo = 2000;
unsigned long milisegundosant = 0;

void IRAM_ATTR contadorpulso()
{
contador++;
}


void setup() {
  Serial.begin(2000000);
  pinMode(pulsador, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pulsador),contadorpulso,FALLING);
}

void loop() {
  unsigned long milisegundosactual = millis();
  
  if(milisegundosactual - milisegundosant >= intervalo)
  {
    milisegundosant = milisegundosactual;
    float frecuencia = contador/(intervalo/1000);
    Serial.print("Frecuencia de los pulsos: ");
    Serial.print(frecuencia);
    Serial.println(" Hz");

    contador = 0;
  }
}
