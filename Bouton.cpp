#define entreeAnalogique 0
int etat;
int oldEtat;

const int WAIT=2;
const int START = -1;
const int STOP=0;
const int br=A0;
const int bp=4;


void setup()
{
  oldEtat=0;
  etat=WAIT;
  pinMode(bp,INPUT);
  Serial.begin(9600);
}

void loop()
{

  int bpstate=digitalRead(bp);
  if (oldEtat== LOW && bpstate==HIGH){
    

if (etat == WAIT)
{
  etat=START;
}
else if (etat== STOP)
{
  etat=START;
}
else if (etat==START)
{
  etat = STOP;
}
}
if (etat==START)
{
 int valeur = analogRead(entreeAnalogique);
 float tension = map( valeur, 0, 1023, 0, 500);
 Serial.print(tension/100.0);
 Serial.print("\t");
 Serial.println(millis());
 delay(500);
}
else if (etat == STOP)
{
  oldEtat=bpstate;
}


oldEtat=bpstate;
delay(10);
}
