#include <Arduino.h>
#include "motor.h"

motor::motor(int in1, int in2, int en, int sensor) {

 
    this->in1 =  in1;
    this->in2 = in2;
    this->en = en;
    this->sensor = sensor;
    init();

}

/*
motor::motor(int in1, int in2, int en) {
  this->in1 = in1;
  this->in2 = in2;
  this->en = en;
  init();
}
*/

void motor::init() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(en, OUTPUT);
    pinMode(sensor, INPUT);
}

void motor::forward(int n) {
  analogWrite(en, n);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motor::backward(int n) {
  analogWrite(en, n);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
}

void motor::kill() {
  analogWrite(en, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

int motor::sense() {
  int value =  digitalRead(sensor);
  return value;
}
