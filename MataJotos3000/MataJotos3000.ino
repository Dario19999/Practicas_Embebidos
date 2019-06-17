#include "Movement.cpp"
#include "BTControl.cpp"
#include "SelfControl.cpp"

Movement moves;
BTControl control;
SelfControl autom;

void setup(){
  Serial.begin(9600);
  moves.entrada();
}

void loop(){
  //moves.move(control.getCommand());
  autom.run();
}
