#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//estados de botones
int botonmas = HIGH;
int botonmenos = HIGH;
int botongiro = HIGH;

//pines de botones
int pinmas = 7;
int pinmenos = 4;
int pingiro = 6; 

//pines de puente H
int ina = 3;
int inb = 5;

//variable que determina el giro 1=derecha y 0=izquierda
int dir = 1; 

//variables de velocidad final y velocidad
int vf = 0, v = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(pinmas, INPUT);
  pinMode(pinmenos, INPUT);
  pinMode(pingiro, INPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
}

void loop() {
  botonmas = digitalRead(pinmas);
  botonmenos = digitalRead(pinmenos);
  botongiro = digitalRead(pingiro);

  if(botonmas == LOW) {
    if(v!=100){
      v += 10;
      vf =  map(v,0,100,0,255);
       if(dir==1){
        //Giro a la derecha
       analogWrite(ina, 0);
       analogWrite(inb, vf);
      }
      else{
        //Giro a la izquierda
       analogWrite(ina, vf);
       analogWrite(inb, 0);
      }
      lcd.clear();
      delay(300);
    }
  }

  if(botonmenos == LOW){
    if(v!=0){
      v-=10;
      vf =  map(v,0,100,0,255);
        if(dir==1){
          //Giro a la derecha
       analogWrite(ina, 0);
       analogWrite(inb, vf);
      }
      else{
        //Giro a la izquierda
       analogWrite(ina, vf);
       analogWrite(inb, 0);
      }
      lcd.clear();
      delay(300);
    }
  }

 if(botongiro == LOW && dir==1) //Si está girando a la derecha, cambiar a la izquierda
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, LOW);
    delay(1000);
    analogWrite(ina, vf);
    analogWrite(inb, 0);
    dir = 0;
  }
    else if(botongiro == LOW && dir==0)//Si está girando a la izquierda, cambiar a la derecha
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, LOW);
    delay(1000);
    analogWrite(ina, 0);
    analogWrite(inb, vf);
    dir = 1;
  }

  if(dir==1){
    lcd.setCursor(1,1);
    lcd.print("Der");
  }
  else
  {
    lcd.setCursor(1,1);
    lcd.print("Izq");
  }
  lcd.setCursor(0,0);
  lcd.print("Velocidad al ");
  lcd.print(String(v)+"%");
}
