#include <Arduino.h>
#include "lib/stepperMotor.hpp"

void setup(){
    for (int i = 0; i <= stepperMotor_n; ++i){
        stepperMotor[i].reload(i);
        pinMode(ConstPul[i], OUTPUT);
        pinMode(ConstDir[i], OUTPUT);
    }
}


void loop(){
    stepperMotor[0].rotate(1200);
}