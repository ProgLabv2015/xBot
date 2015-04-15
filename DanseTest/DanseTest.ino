#include <PLab_ZumoMotors.h>

PLab_ZumoMotors PLab_motors;

void setup(){
  delay(6000);
  PLab_motors.forward(200,10);
  delay(1000);
  PLab_motors.turnLeft(300,90);
  PLab_motors.turnRight(400,180);
  PLab_motors.turnRight(200,90);
  PLab_motors.turnLeft(150,180);
  PLab_motors.turnLeft(300,45);
  PLab_motors.turnRight(300,180);
  PLab_motors.turnRight(300,45);
  PLab_motors.turnRight(300,180);
  
  PLab_motors.turnLeft(250,90);
  PLab_motors.turnRight(300,180);
  PLab_motors.turnRight(200,90);
  PLab_motors.turnLeft(250,180);
  PLab_motors.turnLeft(270,45);
  PLab_motors.turnRight(350,180);
  PLab_motors.turnRight(300,45);
  PLab_motors.turnRight(300,180);
  
  PLab_motors.turnLeft(180,90);
  PLab_motors.turnRight(360,180);
  PLab_motors.turnRight(250,90);
  PLab_motors.turnLeft(200,180);
  PLab_motors.turnLeft(300,45);
  PLab_motors.turnRight(300,180);
  PLab_motors.turnRight(400,45);
  PLab_motors.turnRight(300,180);
  PLab_motors.turnRight(120,70);
  
   
}

void loop(){
}
