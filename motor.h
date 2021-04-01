#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>


class motor {

  private:
    int in1;
    int in2;
    int en;
    int sensor;
    
  public:
    //motor(int a, int b, int c);
    motor(int a, int b, int c, int d);
    
    void init();
    void kill();
    void forward(int n);
    void backward(int n);
    int sense();
    
  
};

#endif
