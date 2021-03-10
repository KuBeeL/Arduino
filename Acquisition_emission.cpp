#define entreeAnalogique5 1
#define entreeAnalogique10 2
#define entreeAnalogique30 3
#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);
int nombre = 3; //Nombre de données souhaitées
float donnees5[100];
float donnees10[100];
float donnees30[100];
int bouton = 2;
int LED = 3;

void acquisition() // gère l'acquisition des données pour les mettre dans les array
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
  delay(500);    
 }
}
void transmission5()
{
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    xbee.print(donnees5[i]);
    xbee.print("&");
    }
}
void transmission10()
{
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    xbee.print(donnees5[i]);
    xbee.print("&");
    }
}
void transmission30()
{
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    xbee.print(donnees5[i]);
    xbee.print("&");
    }
}

void setup()
{
    xbee.begin(9600);                 
    Serial.begin(9600);
    acquisition(); //acquisition des données
    xbee.print("---------");
    xbee.print("transmission 5V&");
    transmission5();//Transmission
    xbee.print("transmission 10V&");
    transmission10();
    xbee.print("transmission 30V&");
    transmission30();
    Serial.println("----------");
    pinMode(bouton, INPUT);
    pinMode(LED, OUTPUT);
    Serial.println("sTest");
}

void loop()
{

}
