


// TIL KJØRING
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoReflectanceSensorArray reflectanceSensors;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
int lastError = 0;

// This is the maximum speed the motors will be allowed to turn.
// (400 lets the motors go at top speed; decrease to impose a speed limit)
const int MAX_SPEED = 200;
// Set constants for PID control
const float KP = 0.5;  // Proportional constant
const float KD = 6;    // Derivative constant
const int SV = 2500; // Set-value for position (in the middle of sensors)

// TIL KJØRING FERDIG



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
int lys = 0;
const int ledPin1 = 12;
const int ledPin2 = 11;
int speakerOut = 3;
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
int touchInputL=3;
const int ledPin5 = 6;


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
  pinMode(ledPin5, OUTPUT);
  digitalWrite(ledPin5, LOW);
  
  
  
    // TIL KJØRING
  reflectanceSensors.init();
  button.waitForButton();  // wait to start calibration

  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  int i;
  for(i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
      
    reflectanceSensors.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(0,0);

  // Turn off LED to indicate we are through with calibration
  digitalWrite(13, LOW);
  
  // Wait for the user button to be pressed and released
  button.waitForButton();
  // TIL KJØRING FERDIG
}

int getCount(){
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

/** One snore lasts ca 4 seconds. If you write 12, there will be 3 snores. If you write 11,
there will therefore be 2 snores, and it'll last ca 8 seconds. */
void snoore(int durationSeconds){
  for(int i = 0; i < durationSeconds/4; i++){
    for(int i = 0; i < 220; i += 5){
       tone(speakerOut, 31 + i, 23);
       delay(24); 
    }
    delay(150);
    for(int i = 1800; i > 0; i -= 25){
      tone(speakerOut, 31 + i, 25);
      delay(25);
    }
    delay(1000);
   }
 }


void happy(int durationSeconds){
  int tones[] = {2093, 2349, 2794, 3136, 3520, 3951};
  int randnum;
  int milliseconds = 0;
  boolean turn = true;
  
  while(milliseconds < durationSeconds*1000){
      randnum = random(0,6);
    if(turn){
      tone(speakerOut, tones[randnum], 180*1.2);
      delay(200*1.2);
      milliseconds += 200*1.2;
      turn = false;
    }else{
      tone(speakerOut, tones[randnum], 80*1.2);
      delay(100*1.2);
      milliseconds += 100*1.2;
      turn = true;
    }
  }
}

void sad(int durationSeconds){
  int tones[] = {123,131,117,110};
  int randnum;
  int milliseconds;
  
  while(milliseconds < durationSeconds*1000){
    randnum = random(0,4);
    tone(speakerOut, tones[randnum]*4, 800);
    delay(800); 
     milliseconds += 800; 
  }
} 

void driving(){
  unsigned int sensors[6];

  int pv = reflectanceSensors.readLine(sensors);
  
  // Our "error" is how far we are away from the center of the line, which
  // corresponds to position 2500.
  int error = pv - SV; 
  // do PD computation ( Integral is not used)
  int speedDifference = KP*error + KD * (error - lastError);
  
  lastError = error;

  // Get individual motor speeds.  The sign of speedDifference
  // determines if the robot turns left or right.
  int m1Speed = MAX_SPEED + speedDifference;
  int m2Speed = MAX_SPEED - speedDifference;
  
  if((sensors[5] > 40 && sensors[5] < 160) && (sensors[0] > 40 && sensors[0] < 160) && post1 == true){
    motors.setSpeeds(0,0);
    delay(2000);
  }
    if((sensors[5] > 790 && sensors[5] < 860) && (sensors[0] > 790 && sensors[0] < 860) && post2 == true){
    motors.setSpeeds(0,0);
    delay(3000);
  }
    if((sensors[5] > 670 && sensors[5] < 770) && (sensors[0] > 670 && sensors[0] < 770) && post3 == true){
    motors.setSpeeds(0,0);
    delay(4000);
  }
    if((sensors[5] > 200 && sensors[5] < 300) && (sensors[0] > 200 && sensors[0] < 300) && post4 == true){
    motors.setSpeeds(0,0);
    delay(5000);
  }
    if((sensors[5] > 600 && sensors[5] < 650) && (sensors[0] > 600 && sensors[0] < 650) && post5 == true){
    motors.setSpeeds(0,0);
    delay(6000);
  }

  // Here we constrain our motor speeds to be between 0 and MAX_SPEED.
  // Generally speaking, one motor will always be turning at MAX_SPEED
  // and the other will be at MAX_SPEED-|speedDifference| if that is positive,
  // else it will be stationary.  For some applications, you might want to
  // allow the motor speed to go negative so that it can spin in reverse.
  else{
  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;
  if (m1Speed > MAX_SPEED)
    m1Speed = MAX_SPEED;
  if (m2Speed > MAX_SPEED)
    m2Speed = MAX_SPEED;

  motors.setSpeeds(m1Speed, m2Speed);
  delay(50);
  motors.setSpeeds(0,0);
  }
}
  

void loop(){

  happy(10);
  
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
   count = getCount();
   if(count>2 && count < 20){
    soundP1 = true;
  }
  
  // KJØRING
  
  
  if (soundP1){
    post1 = false;
    timePost1 = millis();
    hunger4++;
  }
    /* sett inn kode for oppførsel på post1
    ...
    */
    
    //dette er det siste som gjøres på posten
    
  }  
  if (post2 == true && sensorP2 == true){
    /* sett inn kode for oppførsel på post2
    ...
    */
   count = getCount();
   if(count>20 && count < 40){
    soundP2 = true;
  }
  if(soundP2){
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
    if (touchValueR == HIGH) || touchValueL == HIGH{
      digitalWrite(ledPin5, HIGH);
      delay(50);
      digitalWrite(ledPin5, LOW);
      delay(50);
      digitalWrite(ledPin5, HIGH);
      delay(50);
      digitalWrite(ledPin5, LOW);
      delay(50);
      digitalWrite(ledPin5, HIGH);
      delay(50);
      digitalWrite(ledPin5, LOW);
      delay(50);
    
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
  
