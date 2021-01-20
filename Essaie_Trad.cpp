#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);

void Trad(n){
  if(n == 13){
    Serial.println('');
  }
  if(n == 97){
    Serial.print('a');
  }
  if(n == 98){
    Serial.print('b');
  }
  if(n == 99){
    Serial.print('c');
  }
  
} 
void setup()
{
    xbee.begin(9600);                 
    Serial.begin(9600);                     
}
 
void loop()
{
  if(xbee.available()) {
    while(xbee.available())  {
      Trad(xbee.read());
      }
    }
}
