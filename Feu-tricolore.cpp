void setup()
{
  pinMode(13, OUTPUT);//Vert Droit
  pinMode(12, OUTPUT);//Orange Droit
  pinMode(11, OUTPUT);//Rouge Droit
  pinMode(7, OUTPUT);//Vert Gauche
  pinMode(6, OUTPUT);//Orange Gauche
  pinMode(5, OUTPUT);//Rouge Gauche
  pinMode(10, INPUT);//lecture bouton
}
  void normal(){    
    digitalWrite(11, HIGH); 
    digitalWrite(7, HIGH);
    delay(4500);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    delay(2000);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
    delay(4500);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(2000);
    //Fonctionnement normal du feu
  }
  void clignotant(){    
    digitalWrite(12, HIGH);
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    digitalWrite(6, LOW);
    delay(500);
    //Orange clignotant
  }
  void reset(){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    //Cette fonction sert à éteindre toutes les LEDs, pour éviter les erreurs
  }

void loop(){
int Bouton = digitalRead(10);
  
  if (Bouton == HIGH){
    reset();
    clignotant();
  }
  if (Bouton == LOW){
    reset();
    normal();
  }
}
