#include <NewPing.h>
#include <Servo.h>

int trig = 13;
int echo = 12;
int max_dist = 200;

NewPing sonar(trig, echo, max_dist);

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo1.attach(11);
  servo2.attach(10);
  servo3.attach(9);
}

void loop() {

  Serial.println(sonar.ping_cm());
  delay(500);
  if(sonar.ping_cm() <= 10){
     servo1.write(0);
  }else{
    servo1.write(90);
  }
  

}
