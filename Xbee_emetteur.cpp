#define entreeAnalogique5 1
#define entreeAnalogique10 1
#define entreeAnalogique30 1
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
  int valeurLue5 = analogRead(entreeAnalogique5);
  int valeurLue10 = analogRead(entreeAnalogique10);
  int valeurLue30 = analogRead(entreeAnalogique30);
  float tensionLue5 = map(valeurLue, 0, 1023, 0, 500);
  float tensionLue10 = map(valeurLue, 0, 1023, 0, 1000);
  float tensionLue30 = map(valeurLue, 0, 1023, 0, 3000);
  
  float tensionLue5 /= 100.0;
  float tensionLue10 /= 100.0;
  float tensionLue30 /= 100.0;  
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
  xbee.println(tensionLue);
  count++;
  delay(300);
}
