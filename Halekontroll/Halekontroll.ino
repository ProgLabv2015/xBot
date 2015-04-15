
#include <Servo.h>


Servo myServo;


void setup(){

  myServo.attach(10);
  
}




void loop(){
  
    myServo.write(45);

    delay(1000);
    myServo.write(135);
    delay(1000);
    
    
  
}
