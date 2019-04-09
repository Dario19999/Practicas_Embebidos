int retardo = 5;
int tempo = 2000;

int botonon = HIGH;
int botonoff = HIGH;

int pinon = 13;
int pinoff = 12;

void setup() {
  pinMode(pinon, INPUT);     //pin de boton on
  pinMode(pinoff, INPUT);     //pin de boton off
  
  pinMode(11, OUTPUT);    // Pin 11 conectar a IN4
  pinMode(10, OUTPUT);    // Pin 10 conectar a IN3
  pinMode(9, OUTPUT);     // Pin 9 conectar a IN2
  pinMode(8, OUTPUT);     // Pin 8 conectar a IN1


}

void loop() {

  botonon = digitalRead(pinon);
  botonoff = digitalRead(pinoff);

  if(botonon == LOW){
    pason();
  }
}

void pason(){
  for(tempo; tempo>=0; tempo-=500){
     digitalWrite(11, LOW); 
     digitalWrite(10, LOW);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, HIGH);  
      delay(tempo); 
      
     digitalWrite(11, LOW); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, LOW);  
      delay(tempo); 
      
     digitalWrite(11, HIGH); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, LOW);  
     digitalWrite(8, LOW);  
     delay(tempo); 
     
     digitalWrite(11, HIGH); 
     digitalWrite(10, LOW);  
     digitalWrite(9, LOW);  
     digitalWrite(8, HIGH);  
     delay(tempo);  
  }
  paso();
}

void paso(){
  do{
     digitalWrite(11, LOW); 
     digitalWrite(10, LOW);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, HIGH);  
     delay(5); 
      
     digitalWrite(11, LOW); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, LOW);  
     delay(5); 
      
     digitalWrite(11, HIGH); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, LOW);  
     digitalWrite(8, LOW);  
     delay(5); 
     
     digitalWrite(11, HIGH); 
     digitalWrite(10, LOW);  
     digitalWrite(9, LOW);  
     digitalWrite(8, HIGH);  
     delay(5);  
  }while(botonoff != LOW);
}

void pasoff(){
  tempo = 0;
  for(tempo; tempo<=2000; tempo+=500){
     digitalWrite(11, LOW); 
     digitalWrite(10, LOW);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, HIGH);  
      delay(tempo); 
      
     digitalWrite(11, LOW); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, HIGH);  
     digitalWrite(8, LOW);  
      delay(tempo); 
      
     digitalWrite(11, HIGH); 
     digitalWrite(10, HIGH);  
     digitalWrite(9, LOW);  
     digitalWrite(8, LOW);  
     delay(tempo); 
     
     digitalWrite(11, HIGH); 
     digitalWrite(10, LOW);  
     digitalWrite(9, LOW);  
     digitalWrite(8, HIGH);  
     delay(tempo);  
  } 
  apagado();
}
void apagado() {      
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }
