#include <Wire.h>

#include "motor.h"

  
  
motor fl(4, 2, 5, A5);
motor fr(A2, A3, 3, A4);
motor bl(9, 8, 10, A1);
motor br(6, 7, 11, A0);

void idle();
void north(int n);
void south(int n);
void west(int n);
void east(int n);
void northeast(int n);
void northwest(int n);
void southwest(int n);
void southeast(int n);
byte command = 0;  
int n = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("BT serial initialized...");
  pinMode(0,INPUT);
  pinMode(1, OUTPUT);  
  idle();
 



}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available() > 0) {
    
    command = Serial.read(); 
    Serial.println(command);  

     switch (command){
    case 1:
      north(n);
      Serial.println("Received North");
      break;
    case 2:
      south(n);
      Serial.println("Received South");
      break;
    case 3:
      east(n);
      break;
    case 4:
      west(n);
      break;
    case 5:
      northeast(n);
      break;
    case 6:
      northwest(n);
      break;
    case 7:
      southeast(n);
      break;
    case 8:
      southwest(n);
      break;
    case 9:
      anticlockwise(n);
      break;
    case 10:
      clockwise(n);
      break;
    case 0:
      idle();
      break;
    default:
      idle();

}}

}


void idle() {
  fl.kill();
  fr.kill();
  bl.kill();
  br.kill();
}

//Translations

void north(int n) {
  fl.forward(n);
  fr.forward(n);
  bl.forward(n);
  br.forward(n);
}

void south(int n) {
  fl.backward(n);
  fr.backward(n);
  bl.backward(n);
  br.backward(n);
}

void east(int n) {
  fl.forward(n);
  fr.backward(n);
  bl.backward(n);
  br.forward(n);
}

void west(int n) {
  fl.backward(n);
  fr.forward(n);
  bl.forward(n);
  br.backward(n);
}

void northeast(int n) {
  fl.forward(n);
  br.forward(n);
}

void northwest(int n) {
  fr.forward(n);
  bl.forward(n);
}

void southeast(int n) {
  fr.backward(n);
  bl.backward(n);
}

void southwest(int n) {
  fl.backward(n);
  br.backward(n);
}

// Rotations

void clockwise(int n) {
  fl.forward(n);
  bl.forward(n);
  fr.backward(n);
  br.backward(n);
}

void anticlockwise(int n) {
  fl.backward(n);
  bl.backward(n);
  fr.forward(n);
  br.forward(n);

}
