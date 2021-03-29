#include <Wire.h>

#include "motor.h"

#define state 3

  
motor fl(4, 2, 5, A5);
motor fr(A2, A3, 6, A4);
motor bl(9, 8, 10, A1);
motor br(12, 7, 11, A0);
//
//void idle();
//void north(int n);
//void south(int n);
//void west(int n);
//void east(int n);
//void northeast(int n);
//void northwest(int n);
//void southwest(int n);
//void southeast(int n);
//void clockwise(int n);
//void anticlockwise(int n);

byte command[2];  
int n = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("BT serial initialized...");
  pinMode(0,INPUT);
  pinMode(1, OUTPUT);  
  pinMode(state, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(state), idle, CHANGE);
  idle();
 



}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available() > 1) {

    for (int i = 0; i < 2; i++)
    {
      command[i] = Serial.read(); 
    }
    
 

     switch (command[0]){
    case 1:
      north(command[1]);
      Serial.println("Received North");
      break;
    case 2:
      south(command[1]);
      Serial.println("Received South");
      break;
    case 3:
      east(command[1]);
      break;
    case 4:
      west(command[1]);
      break;
    case 5:
      northeast(command[1]);
      break;
    case 6:
      northwest(command[1]);
      break;
    case 7:
      southeast(command[1]);
      break;
    case 8:
      southwest(command[1]);
      break;
    case 9:
      anticlockwise(command[1]);
      break;
    case 10:
      clockwise(command[1]);
      break;
    default:
      idle();

}}

  
}
///////////////////////////////////////////////////////////////////////////////////////
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

//  int counterfr = 0;
//  int counterbl = 0;
//  int counterbr = 0;

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
