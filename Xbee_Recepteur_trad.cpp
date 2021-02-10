#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);

void Trad(float n){
  if(n == 10){
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
  if(n == 100){
    Serial.print('d');
  }
  if(n == 101){
    Serial.print('e');
  }
  if(n == 102){
    Serial.print('f');
  }
  if(n == 103){
    Serial.print('g');
  }
  if(n == 104){
    Serial.print('h');
  }
  if(n == 105){
    Serial.print('i');
  }
  if(n == 106){
    Serial.print('j');
  }
  if(n == 107){
    Serial.print('k');
  }
  if(n == 108){
    Serial.print('l');
  }
  if(n == 109){
    Serial.print('m');
  }
  if(n == 110){
    Serial.print('n');
  }
  if(n == 111){
    Serial.print('o');
  }
  if(n == 112){
    Serial.print('p');
  }
  if(n == 113){
    Serial.print('q');
  }
  if(n == 114){
    Serial.print('r');
  }
  if(n == 115){
    Serial.print('s');
  }
  if(n == 116){
    Serial.print('t');
  }
  if(n == 117){
    Serial.print('u');
  }
  if(n == 118){
    Serial.print('v');
  }
  if(n == 119){
    Serial.print('w');
  }
  if(n == 120){
    Serial.print('x');
  }
  if(n == 121){
    Serial.print('y');
  }
  if(n == 122){
    Serial.print('z');
  }
  if(n == 48){
    Serial.print('0');
  }
  if(n == 49){
    Serial.print('1');
  }
  if(n == 50){
    Serial.print('2');
  }
  if(n == 51){
    Serial.print('3');
  }
  if(n == 52){
    Serial.print('4');
  }
  if(n == 53){
    Serial.print('5');
  }
  if(n == 54){
    Serial.print('6');
  }
  if(n == 55){
    Serial.print('7');
  }
  if(n == 56){
    Serial.print('8');
  }
  if(n == 57){
    Serial.print('9');
  }
  if(n == 32){
    Serial.print(' ');
  }
  }
  if(n == 124){
    Serial.print('|');
  }
  }
  if(n == 46){
    Serial.print('.');
  }
  }
  if(n == 38){
    Serial.print('&');
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
