


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
  
  
  
    // TIL KJØRING
  reflectanceSensors.init();
  button.waitForButton();  // wait to start calibration

  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  int i;
  for(i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70)){
      motors.setSpeeds(-200, 200);
    }
    else{
      motors.setSpeeds(200, -200);
    }
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

  
  /*sett inn kode for når de forskjellige tilstandene skal være true og false
  */
  time = millis();
  
  if (time - timePost1 > 10000){
     post1 = true;
  }
  else if (time - timePost2 > 20000){
     post2 = true;
  }
  else if (time - timePost3 > 30000){
     post3 = true;
  }
  else if ((time - timePost4 > 40000) || (hunger4 >= 5)){
     post4 = true;
  }
  else if (time - timePost5 > 50000){
     post5 = true;
  }
  
  driving();
  
  
  if (post1==true && sensorP1 == true){
    delay(500);
    post1 = false;
    timePost1 = millis();
    hunger4++;
  }  
  else if (post2 == true && sensorP2 == true){
    delay(500);
    post2 = false;
    timePost2 = millis();
    hunger4++;
  
    
     //dette er det siste som gjøres på posten
    
  }
  else if (post3 == true && sensorP3 == true){
    post3 = false;
    timePost3 = millis();
    hunger4++;
   
  }
  else if (post4 == true && sensorP4 == true){
    hunger4 = 0;
    
    post4 = false;
    timePost4 = millis();
   
  }
  else if (post5 == true && sensorP5 == true){
   
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
   

  //delay(1000);
}
  
