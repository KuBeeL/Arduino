#define entreeAnalogique5 1
#define entreeAnalogique10 2
#define entreeAnalogique30 3
#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);
int nombre = 100;
float donnees5[100];
float donnees10[100];
float donnees30[100];

void acquisition()
{
  for (byte i = 0; i <= nombre; i = i + 1) {
  int valeurLue5 = analogRead(A1);
  int valeurLue10 = analogRead(A2);
  int valeurLue30 = analogRead(A3);

  float tensionLue5 = map(valeurLue5, 0, 1023, 0, 500);
  float tensionLue10 = map(valeurLue10, 0, 1023, 0, 1000);
  float tensionLue30 = map(valeurLue30, 0, 1023, 0, 3000);
  
  tensionLue5 = tensionLue5/100.0;
  tensionLue10 = tensionLue10/100.0;
  tensionLue30 = tensionLue30/100.0;

  donnees5[i] = tensionLue5;
  donnees10[i] = tensionLue5;
  donnees30[i] = tensionLue5;
    
}
}


void setup()
{
    xbee.begin(9600);                 
    Serial.begin(9600);
    acquisition();
    for (byte i = 0; i < nombre; i = i + 1) {
    Serial.println(donnees5[i]);
    }
    Serial.println("----------");
    /*
    Serial.println(donnees5[2]);
    Serial.println(donnees10[2]);                         
    Serial.println(donnees30[2]); 
    */   
}

void loop()
{
  /*
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
  xbee.print(tensionLue5);
  xbee.print("&");
  xbee.print(tensionLue10);
  xbee.print("&");  
  xbee.print(tensionLue30);
  xbee.print("&");  
  xbee.println("-------");
  xbee.print("&");
  delay(1000);ù
  */
}
