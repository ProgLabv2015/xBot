#include <PLab_ZumoMotors.h>

PLab_ZumoMotors PLab_motors;
//For å finne ut hvilken post den er på
boolean post1 = false;
boolean post2 = false;
boolean post3 = false;
boolean post4 = false;
boolean post5 = false; 

boolean sensorP1 = false;
boolean sensorP2 = false;
boolean sensorP3 = false;
boolean sensorP4 = false;
boolean sensorP5 = false;

boolean soundP1 = false;
boolean soundP2 = false;
boolean soundP3 = false;
boolean soundP4 = false;
boolean soundP5 = false;

long time= millis();
long timePost1 = millis();
long timePost2 = millis();
long timePost3 = millis();
long timePost4 = millis();
long timePost5 = millis();

// til lydsensor paa Hovedbot
int micValue;
int micInput = A0;
int toneLength;
int count;
int waitingTime;
int timeWaited = 0;
/*
Sett inn initialverdier til post1
*/

/*
Sett inn initialverdier til post2
*/


// til Post 3
boolean happy3;
int count = 0;
int lys = 0;
const int ledPin1 = 12;
const int ledPin2 = 11;
int speakerOut = 9;
int frequency = 880;



/*
Sett inn initialverdier til post4
*/
int hunger4 = 0;

// til Post 5
boolean happy5;
int touchValueL;
int touchValueR;
int touchInputR=2;
int touchInputL=4;


void setup(){
 

  /*
  sett inn setup til post1
  */
  
   /*
  sett inn setup til post2
  */
    // setup til lydsensor hovedbot
  pinMode(micInput, INPUT);
  waitingTime = 10000;
  micValue = 0;
  
  // til post 3
  pinMode(speakerOut, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  Serial.begin(9600);
  
   /*
  sett inn setup til post4
  */
  
  
   // post 5
  pinMode(touchInputR, INPUT);
  pinMode(touchInputL, INPUT);
  
}

void getCount(){
 micValue = analogRead(micInput);
  if (micValue > 500){
    count +=1;
    timeWaited = 0;
    while(timeWaited < waitingTime){
      micValue = analogRead(micInput);
      if (micValue > 500){
        count +=1;
      }
      timeWaited += 100;
      delay(50);
    }
    timeWaited = 0;
    return count;
  }else{
   return getCount();
  }
}

void loop(){
  /*sett inn kode for når de forskjellige tilstandene skal være true og false
  */
  time = millis();
  
  if (time - timePost1 > 10000){
     post1 = true;
  }
  if (time - timePost2 > 20000){
     post2 = true;
  }
  if (time - timePost3 > 30000){
     post3 = true;
  }
  if ((time - timePost4 > 40000) || (hunger4 >= 5)){
     post4 = true;
  }
  if (time - timePost5 > 50000){
     post5 = true;
  }
  
   /* Sett inn kode for å finne ut hvilken stasjon/post den er på
  Her registrerer  mikrofonen en lyd. hvis den registrerer flere lyder innen den 10 sekunder, saa oeker counteren.
  */
  /*micValue = analogRead(micInput);
  if (micValue > 500){
    count +=1;
    timeWaited = 0;
    while(timeWaited < waitingTime){
      micValue = analogRead(micInput);
      if (micValue > 500){
        count +=1;
      }
      timeWaited += 100;
      delay(50);
    }
    timeWaited = 0;
  }*/
  
  
 // her sjekker den hva counteren er og setter tilsvarende SoundPost til true
  /*if(count>2 && count < 20){
    soundP1 = true;
  }
  if(count>20 && count < 40){
    soundP2 = true;
  }
  if(count>40 && count < 60){
    soundP3 = true;
  }
  if(count>60 && count < 80){
    soundP4 = true;
  }
  if(count>80 && count < 100){
    soundP5 = true;
  }
  count = 0;*/
  
  if (post1==true && sensorP1 == true){
    /* sett inn kode for oppførsel på post1
    ...
    */
    PLab_motors.backward(200,5);
    PLab_motors.turnRight(200,60);
    PLab_motors.turnLeft(200,180);
    PLab_motors.forward(200, 7);
    PLab_motors.turnRight(200,360);
    PLab_motors.backward(200,7);
    PLab_motors.turnLeft(200,180);
    PLab_motors.forward(200, 7);
    PLab_motors.turnRight(200,360);
    PLab_motors.backward(200,7);
    PLab_motors.turnRight(200,90);
    PLab_motors.forward(200, 7);
    PLab_motors.turnRight(200,360);
    PLab_motors.backward(200,7);
    PLab_motors.turnLeft(200,180);
    PLab_motors.forward(200, 7);
    PLab_motors.turnRight(200,360);
    PLab_motors.backward(200,7);
    PLab_motors.turnRight(200,120);
    
    
    //dette er det siste som gjøres på posten
    post1 = false;
    timePost1 = millis();
    hunger4++;
  }
  if (post2 == true && sensorP2 == true){
    /* sett inn kode for oppførsel på post2
    ...
    */
   count = getCount();
   if(count>20 && count < 40){
    soundP2 = true;
  }
  if(suondP2){
   post2 = false;
    timePost2 = millis();
    hunger4++;
  }
    
     //dette er det siste som gjøres på posten
    
  }
  if (post3 == true && sensorP3 == true){
    /* sett inn kode for oppførsel på post3
    ...
    */
    count = getCount();
   if(count>40 && count < 60){
    soundP3 = true;
   }
   if(soundP3){
    post3 = false;
    timePost3 = millis();
    hunger4++;
   }
    
     //dette er det siste som gjøres på posten
    
  }
  if (post4 == true && sensorP4 == true){
   count = getCount();
   if(count>60 && count < 80){
    soundP4 = true;
   }
   if(soundP4){
    hunger4 = 0;
    
    post4 = false;
    timePost4 = millis();
   }
    
  }
  if (post5 == true && sensorP5 == true){
   count = getCount();
   if(count>80 && count < 100){
    soundP5 = true;
   }
   if(soundP5){
    
    touchValueR = digitalRead(touchInputR);
     touchValueL = digitalRead(touchInputL);
    if (touchValueR == HIGH){
      // do something
    
    } else if (touchValueL == HIGH){
      // do something
    }
     //dette er det siste som gjøres på posten
    post5 = false;
    timePost5 = millis();
    happy5 = true;
   }
   
  }
  
  Serial.println(time);
  Serial.println("Post1: "); 
  Serial.println(timePost1);
  Serial.println("Post2: "); 
  Serial.println(timePost2);
  Serial.println("Post3: "); 
  Serial.println(timePost3);
  Serial.println("Post4: "); 
  Serial.println(timePost4);
  Serial.println("Post5: "); 
  Serial.println(timePost5);
  Serial.println(" ");
  
  delay(1000);
}
  
