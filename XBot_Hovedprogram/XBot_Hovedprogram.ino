#include <PLab_ZumoMotors.h>

PLab_ZumoMotors PLab_motors;
//For å finne ut hvilken post den er på
boolean post1 = false;
boolean post2 = false;
boolean post3 = false;
boolean post4 = false;

/*
Sett inn initialverdier til post1
*/

/*
Sett inn initialverdier til post2
*/


// til Post 3
boolean happy3;
int count = 0;
int time = 0;
int lys = 0;
const int ledPin1 = 12;
const int ledPin2 = 11;
int speakerOut = 9;
int micInput = A0;
int micValue = 0;
int frequency = 880;

/*
Sett inn initialverdier til post4
*/


void setup(){
  /*
  sett inn setup til post1
  */
  
   /*
  sett inn setup til post2
  */
  
  // til post 3
  pinMode(speakerOut, OUTPUT);
  pinMode(micInput, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  Serial.begin(9600);
  
   /*
  sett inn setup til post4
  */
}

void loop(){
  /*sett inn kode for når de forskjellige tilstandene skal være true og false
  ...
  */
  
  /* Sett inn kode for å finne ut hvilken stasjon/post den er på
  ...
  */
  
  if (post1==true){
    /* sett inn kode for oppførsel på post1
    ...
    */
  }  
  if (post2 == true){
    /* sett inn kode for oppførsel på post2
    ...
    */
  }
  if (post3 == true){
    /* sett inn kode for oppførsel på post3
    ...
    */
  }
  if (post4 == true){
    /* sett inn kode for oppførsel på post4
    ...
    */
  }
}
  
  
  
