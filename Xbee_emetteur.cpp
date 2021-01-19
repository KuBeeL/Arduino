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
  String phrase = "Envoi du mot Sending";
  phrase += count;
  Serial.println(phrase);
  xbee.println(phrase);
  count++;
  delay(300);
}
