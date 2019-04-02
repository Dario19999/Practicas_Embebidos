#include <Servo.h>

Servo servo;

const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;    
int rojo = 0;  
int verde = 0;  
int azul = 0;
int pasos = 0;
bool colorFlag = false;  

bool r=false, g=false, b=false;
void setup(){  
  Serial.begin(9600); 
  servo.attach(6);
  servo.write(140);
  //sensor de color
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH); 
  //motor a pasos
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
   
}  

   
void loop(){  
  
  
  Serial.print("   ");  
  Serial.print(rojo, DEC);  
  Serial.print("   ");  
  Serial.print(verde, DEC);  
  Serial.print("   ");  
  Serial.print(azul, DEC);  
  encender();
}
void iscolor(){
  if (rojo < azul && verde > azul && rojo < 35) 
  {  
    r=true;
    if(colorFlag){
      servo.write(40);
    }
    Serial.println("   Rojo");    
  }   
  else if (azul < rojo && azul < verde && verde < rojo)  
  {  
    b=true;
    if(colorFlag){
      servo.write(140);
    }
    Serial.println("   Azul");        
  }  

  else if (rojo > verde && azul > verde )  
  {  
    Serial.println("   Verde");      
  }  
  else{
    Serial.println("  ");  
  }
  delay(900);     
}
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  iscolor(); 
}


int pasosRojos = 0, pasosAzul = 0;
void putazo(){
  if(r){
    pasosRojos++;
    if(pasosRojos == 4){
      servo.write(140);
      r = false;
      pasosRojos = 0;
    }else if(pasosRojos == 4){
      servo.write(40);
    }
  }
  if(b){
    pasosAzul++;
    if( pasosAzul == 4){
      servo.write(40);
      b =false;
      pasosAzul = 0;
    }else if(pasosAzul == 3){
      servo.write(140);
    }
  }
}

void encender()
{ 
    do{
    for(int i = 0; i <=450; i++){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(5);   
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, HIGH);            
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
    }
    putazo();
    color();
  }while(true);
  for(int i = 0; i <= pasos; i++){
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(5);   
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
      digitalWrite(8, HIGH);            
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(5);
    }
    Serial.print("PUTAZOOO");
    iscolor();
    colorFlag=false;
    encender();
}

void apagar()
{
   digitalWrite(11, LOW); 
   digitalWrite(10, LOW);  
   digitalWrite(9, LOW);  
   digitalWrite(8, LOW);  
}
  
