//#include <NewPing.h>
#include <Servo.h>

int trig = 13;
int echo = 12;
int max_dist = 200;

//NewPing sonar(trig, echo, max_dist);

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  //pinMode(trig, OUTPUT);
  //pinMode(echo, INPUT);
  servo1.attach(A0);
  servo2.attach(A1);
}

void loop() {

  //Serial.println(sonar.ping_cm());
  delay(1000);
  //if(sonar.ping_cm() <= 10){
     servo1.write(125);
     servo2.write(0);
  //}else{
  delay(1000);
    servo1.write(90);
    servo2.write(90);
  //}
  

}
