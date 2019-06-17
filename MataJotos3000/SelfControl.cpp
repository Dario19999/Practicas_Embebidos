#include <NewPing.h>
#include "Movement.cpp"

int trig = 13;
int echo = 12;
int max_dist = 50;

NewPing sonar(trig, echo, max_dist);

class SelfControl{
  
  char front = 'F';
  char back = 'B';
  char left = 'l';
  char fullLeft = 'L';
  char right = 'r';
  char fullRight = 'R';
  char backLeft = 'i';
  char backRight = 'd';
  
  Movement mov;

  public:
  void run(){
    if(sonar.ping_cm() == max_dist){
      do{
        mov.move(fullLeft);
      }while(sonar.ping_cm() == max_dist);
      mov.move(front);

      if(sonar.ping_cm() <= 5){
        do{
          mov.modo_diablo();
          mov.move(back);
          mov.move(front);
        }while(sonar.ping_cm() != max_dist);
      }
    }
  }
};
