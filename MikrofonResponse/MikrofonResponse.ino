
#include <SoftwareSerial.h>

#include <NewPing.h>


#define trigPin 4
#define echoPin 5
#define soundPin 8

#define MAX_DISTANCE 40

NewPing sonar(trigPin,echoPin, MAX_DISTANCE);

long dist;

boolean lastState = false;
boolean currState = false;




void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(soundPin, OUTPUT);

  digitalWrite(soundPin, LOW);  
  digitalWrite(trigPin, LOW);
}

void loop(){
  lastState = currState;
  dist = sonar.ping_cm();
  currState = dist < 10 && dist > 0;
  if (currState == true && lastState == true){
    digitalWrite(soundPin, HIGH);
    delay(3000);
    digitalWrite(soundPin, LOW);
  }
  delay(2000);


  Serial.println("lastState");
  Serial.println(lastState);
  Serial.println("currState");
  Serial.println(currState);
  Serial.println(dist);
}


