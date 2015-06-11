/* 
  TECHMAKE DEMOS - Sensor Ultrasonico
  
  * Descripcion del DEMO:
    * Medir la distancia de lo que el sensor tiene frente a el. 
    * En esta ocasion se utilizo el Sensor Ultrasonico HC-SR04, pero se puede utilizar cualquier utlrasonico.
  
  * Material Utilizado:
    * (1) Sensor Ultrasonico HC-SR04: http://www.techmake.com/00029.html
    * (1) Pantalla LCD: http://www.techmake.com/productos/lcds.html
    * (1) Potenciometro: http://www.techmake.com/productos/components/potenciometros.html
    * (20) Cables Jumper Wire M/M de 20cm: http://www.techmake.com/00043.html
    * (1) Arduino Uno R3: http://www.techmake.com/00001.html
  
  * Conexiones:
  
     * LCD
        * 1 = GND
        * 2 = 5V
        * 3 = Pin central del potenciometro (para ajustar el contraste)
        * 4 = Arduino Pin Digital 12
        * 5 = GND
        * 6 = Arduino Pin Digital 11
        * 11 = Arduino Pin Digital 5
        * 12 = Arduino Pin Digital 4
        * 13 = Arduino Pin Digital 3
        * 14 = Arduino Pin Digital 2
        * 15 = 5V
        * 16 = GND
    
Este codigo fue creado por TechMake Electronics,
con mucha ayuda de la comunidad Arduino y SparkFun.
Este codigo es completamente gratuito para cualquier uso.
Visita http://www.techmake.com para mas DEMOS y tutoriales.
Visita http://www.arduino.cc para aprender mas sobre el Arduino.
Visita http://www.sparkfun.com para conocer todo de SparkFun.

Creado el 11/Jun/2015 por David S. Gonzalez P.
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int trigPin = 9;
int echoPin = 8;
float t; // Tiempo
float d; // Distancia

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.begin(16, 2); // Enciende el LCD y le dice al Arduino que tan grande es
  lcd.clear(); // Para limpiar el LCD
  
  lcd.setCursor(0,0);
  lcd.print("Dist.:"); // Primer renglon
  lcd.setCursor(0,1);
  lcd.print("techmake.com");
}

void loop() 
{  
  // Se mandan los pulsos y por ecuasion fisica d = V*t obtenemos la distancia
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  d = pulseIn(echoPin, HIGH);
  d = (d/2) / 29.1;
  delay(500);
  
  // Este sensor en particular tiene la capacidad de medir hasta 5 metros optimos
  
  if (d < 500)
  { 
    // Cuando es menor a 1 metro, lo despliega en centimetros
    
    if (d < 100)
    {
      lcd.setCursor(0,0);
      lcd.print("Dist.:          ");
      
      lcd.setCursor(7,0);
      lcd.print(d);
      lcd.print(" cm");
    }
    
    // Cuando es mayor a 1 metro, lo despliega en metros
    
    if (d >= 100)
    {
      lcd.setCursor(0,0);
      lcd.print("Dist.:          ");
      
      lcd.setCursor(7,0);
      lcd.print(d/100);
      lcd.print(" m");
    }   
  }
  
  // Si no llega a medir nada, detecta que esta fuera de rango
  
  else
  {
    lcd.setCursor(0,0);
    lcd.print(" FUERA DE RANGO ");
  }
  
}
  
