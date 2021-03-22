#include <SoftwareSerial.h>
SoftwareSerial xbee(2, 3);
#define entreeAnalogique 0
//Déclarations bouton
int etat;
int oldEtat;
const int WAIT=2;
const int START = -1;
const int STOP=0;
const int br=A0;
const int bp=4;

//déclarations acquisition
int nombre = 0;
float donnees5[100];
float donnees10[100];
float donnees30[100];
int i = 0;

void acquisition() // gère l'acquisition des données pour les mettre dans les array
{
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
  donnees10[i] = tensionLue10;
  donnees30[i] = tensionLue30;
  i = i+1;
  nombre = nombre+1;
  delay(1000);    
}

void transmission5() //transmission de l'array contenant les données du 5V
{
    Serial.println("----------5V----------");
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    Serial.println(donnees5[i]);
    xbee.print(donnees5[i]); //Envoie les données via le xbee
    xbee.print("&"); //Signal à l'autre arduino la séparation entre les données
    }
    memset(donnees5, -1, sizeof(donnees5)); //Reset toutes les données stockées une fois transmises
}
void transmission10()
{
    Serial.println("----------10V----------");
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    Serial.println(donnees10[i]);
    xbee.print(donnees10[i]); //Envoie les données via le xbee
    xbee.print("&"); //Signal à l'autre arduino la séparation entre les données
    }
    memset(donnees10, -1, sizeof(donnees10)); //Reset toutes les données stockées une fois transmises
}
void transmission30()
{
    Serial.println("----------30V----------");
    for (byte i = 0; i < nombre; i = i + 1) { //print toutes les données 
    Serial.println(donnees30[i]);
    xbee.print(donnees30[i]); //Envoie les données via le xbee 
    xbee.print("&"); //Signal à l'autre arduino la séparation entre les données
    }
    memset(donnees30, -1, sizeof(donnees30)); //Reset toutes les données stockées une fois transmises
}


void setup()
{
  oldEtat=0;
  etat=WAIT;
  pinMode(bp,INPUT);
  Serial.begin(9600);
  xbee.begin(9600);
}

void loop()
{

  int bpstate=digitalRead(bp); //Lit le bouton
  if (oldEtat== LOW && bpstate==HIGH){ //détecte un changement d'état du bouton
    

if (etat == WAIT) //Etat à l'initialisation
{
  etat=START;
  Serial.println("Wait");
}
else if (etat== STOP) //Etat après l'acquisition
{
  etat=START;
  Serial.println("Reset après acquisition");
  i = 0; //reset des données
  nombre = 0; //reset des données
}
else if (etat==START) //Etat de transmission
{
  etat = STOP;
  Serial.println("Transmission");
  transmission5();
  transmission10();
  transmission30();
}
}
  
if (etat==START) //Etat d'acquisition
{
acquisition();
Serial.println("Acquisition");
}
else if (etat == STOP) //Etat après la transmission
{
  oldEtat=bpstate;
  //Serial.println("oldetat");
}

oldEtat=bpstate;
delay(10);
}
