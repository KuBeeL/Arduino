#define entreeAnalogique5 1
#define entreeAnalogique10 2
#define entreeAnalogique30 3
#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);
int count;

void setup()
{
    xbee.begin(9600);                 
    Serial.begin(9600);                     
    count = 0;
}

void loop()
{
  analogWrite(A4, 500);
  int valeurLue5 = analogRead(A1);
  int valeurLue10 = analogRead(A2);
  int valeurLue30 = analogRead(A3);
  Serial.println(valeurLue5);
  Serial.println(valeurLue10);
  Serial.println(valeurLue30);
  Serial.println("----------------");
  float tensionLue5 = map(valeurLue5, 0, 1023, 0, 500);
  float tensionLue10 = map(valeurLue10, 0, 1023, 0, 1000);
  float tensionLue30 = map(valeurLue30, 0, 1023, 0, 3000);
  
  tensionLue5 = tensionLue5/100.0;
  tensionLue10 = tensionLue10/100.0;
  tensionLue30 = tensionLue30/100.0;  
  String phrase = "Message";
  Serial.print("Borne 5v: ");
  Serial.print(tensionLue5);
  Serial.println(" V");
  Serial.print("Borne 10v: ");
  Serial.print(tensionLue10);
  Serial.println(" V");
  Serial.print("Borne 30v: ");
  Serial.print(tensionLue30);
  Serial.println(" V");
  Serial.println("-----------");
  //xbee.println(tensionLue);
  delay(1000);
}
