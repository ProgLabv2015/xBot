#include <NewPing.h>


int dist;
int MAX_DISTANCE = 5;

int buzzerPin = 6;
int trigPin = 7;
int echoPin = 8;
int ledPin = 9;



NewPing sonar(trigPin,echoPin, MAX_DISTANCE);




void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
}

void loop(){
  dist = sonar.ping_cm();
  
  if (dist < 5 && dist > 0){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  Serial.println(dist);
}
