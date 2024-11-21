//anemómetro con LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
float veloc1= 0;// entrada A0
int tiempo=0;
int cnt=0;
float v1=0;
float v2=0;
void setup() {
lcd.begin(16, 2); // Fijamos el numero de caracteres y filas
lcd.begin(16, 2); // Fijamos el numero de caracteres y filas
lcd.print(" Anemometro EC"); // Aqi va el mensaje
analogReference(INTERNAL);// pone como referencia interna 1.1V
}
void loop() {
v1 =(analogRead(0)); // lectura de sensor a0
veloc1= (v1*0.190); // 0,190 corresponde a la pendiente de la curva aca deben poner el numero que calcularon
lcd.setCursor(0, 1); // Ponte en la line 1, posicion 0
lcd.print(veloc1); //muestra la velocidad del viento en el LCD
lcd.setCursor(4, 1); // ponte en linea 1, posicion 5
lcd.print("Km/h");
lcd.setCursor(9, 1);
lcd.print("Max");
if (veloc1>v2)v2=veloc1,lcd.print (v2,1); // muestra la velocidad maxima que alcanzo
delay(1000);
}
