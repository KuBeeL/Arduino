#define entreeAnalogique 1
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
  int valeurLue = analogRead(entreeAnalogique);
  float tensionLue = map(valeurLue, 0, 1023, 0, 500);
  float tensionLue /= 100.0;
  String phrase = "Message";
  Serial.println(tensionLue);
  xbee.println(tensionLue);
  count++;
  delay(300);
}
