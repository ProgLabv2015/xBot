#include <NewPing.h>


#define trigPin 4
#define echoPin 5
#define soundPin 8

#define MAX_DISTANCE 40

NewPing sonar(trigPin,echoPin, MAX_DISTANCE);

long dist;

boolean lastState = false;
boolean currState = false;
boolean look = true;




void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(soundPin, OUTPUT);

  digitalWrite(soundPin, LOW);  
  digitalWrite(trigPin, LOW);
}

void loop(){
  if(look){
    lastState = currState;
    dist = sonar.ping_cm();
    currState = dist < 10 && dist > 0;
    if (currState && lastState){
      digitalWrite(soundPin, HIGH);
      delay(3000);
      digitalWrite(soundPin, LOW);
      look = false;
    }else{
      delay(2000);
    }
  }else{
    lastState = currState;
    dist = sonar.ping_cm();
    currState = dist < 10 && dist > 0;
    if (!(currState && lastState)){
      look = true;
    }else{
      delay(2000);
    }
  }
}
