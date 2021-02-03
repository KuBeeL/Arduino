#include <Wire.h>
#include <DS3231.h>
byte Year ;
byte Month ;
byte Date ;
byte DoW ;
byte Hour ;
byte Minute ;
byte Second ;
bool Century  = false;
bool h12 ;
bool PM ;
//Objets
DS3231 Clock;
void setup() {
 //Initialise Serial USB
 Serial.begin(9600);
 Serial.println(F("Initialize System"));
 Wire.begin();
}
void loop() {
 setDate();
 readRTC();
}
void readRTC( ) {
 ////lit le temps de la clock
 Serial.print(Clock.getYear(), DEC);
 Serial.print("-");
 Serial.print(Clock.getMonth(Century), DEC);
 Serial.print("-");
 Serial.print(Clock.getDate(), DEC);
 Serial.print(" ");
 Serial.print(Clock.getHour(h12, PM), DEC); //24-hr
 Serial.print(":");
 Serial.print(Clock.getMinute(), DEC);
 Serial.print(":");
 Serial.println(Clock.getSecond(), DEC);
 delay(1000);
}
void setDate( ) {
 if (Serial.available()) {
   GetDateStuff(Year, Month, Date, DoW, Hour, Minute, Second);
   Clock.setClockMode(false);  
   Clock.setSecond(Second);
   Clock.setMinute(Minute);
   Clock.setHour(Hour);
   Clock.setDate(Date);
   Clock.setMonth(Month);
   Clock.setYear(Year);
   Clock.setDoW(DoW);
 }
}
void GetDateStuff(byte& Year, byte& Month, byte& Day, byte& DoW, byte& Hour, byte& Minute, byte& Second) {
 boolean GotString = false;
 char InChar;
 byte Temp1, Temp2;
 char InString[20];
 byte j = 0;
 while (!GotString) {
   if (Serial.available()) {
     InChar = Serial.read();
     InString[j] = InChar;
     j += 1;
     if (InChar == 'x') {
       GotString = true;
     }
   }
 }
 Serial.println(InString);
 // Année
 Temp1 = (byte)InString[0] - 48;
 Temp2 = (byte)InString[1] - 48;
 Year = Temp1 * 10 + Temp2;
 // Mois
 Temp1 = (byte)InString[2] - 48;
 Temp2 = (byte)InString[3] - 48;
 Month = Temp1 * 10 + Temp2;
 // Date
 Temp1 = (byte)InString[4] - 48;
 Temp2 = (byte)InString[5] - 48;
 Day = Temp1 * 10 + Temp2;
 // Jour de semaine
 DoW = (byte)InString[6] - 48;
 // Heure
 Temp1 = (byte)InString[7] - 48;
 Temp2 = (byte)InString[8] - 48;
 Hour = Temp1 * 10 + Temp2;
 // Minute
 Temp1 = (byte)InString[9] - 48;
 Temp2 = (byte)InString[10] - 48;
 Minute = Temp1 * 10 + Temp2;
 // Seconde
 Temp1 = (byte)InString[11] - 48;
 Temp2 = (byte)InString[12] - 48;
 Second = Temp1 * 10 + Temp2;
}
