#include <Servo.h>
float toArmPosition;
void armreach(float toArmPosition, int speed, int armNum){//armNum:1(left).2:(right); to arm reach:90~30(90:the initial position,30:the furthest postion; speed:255MAX)
    static float currentArmPositionLeft = 90;
    static float currentArmPositionRight = 90;
    if(armNum == 1){
        if(currentArmPosition > toArmPosition){
            if(!(millis()%50)){
                pos2 += 0.004*speed;
                L5.write((currentArmPositionLeft+pos2)*0.95);
                L3.write((currentArmPositionLeft+7)-pos2);
                L4.write((currentArmPositionLeft-2*pos2)*1.1);
                currentArmPositionLeft -= pos2;
            }
        }
        if(currentArmPosition < toArmPosition){
            if(!(millis()%50)){
                pos2 += 0.004*speed;
                L5.write((currentArmPositionLeft+pos2)*0.95);
                L3.write((currentArmPositionLeft+7)-pos2);
                L4.write((currentArmPositionLeft-2*pos2)*1.1);
                currentArmPositionLeft += pos2;
            }
        }
    }
    if(armNum == 2){
        if(currentArmPosition > toArmPosition){
            if(!(millis()%50)){
                pos2 += 0.004*speed;
                L().write((currentArmPositionRight()pos2)*0.95);//fill the ()
                L().write(currentArmPositionRight()pos2);//fill the ()
                L().write((currentArmPositionRight()2*pos2)*1.1);//fill the ()
                currentArmPositionRight -= pos2;
            }
        }
        if(currentArmPosition < toArmPosition){
            if(!(millis()%50)){
                pos2 += 0.004*speed;
                L().write((currentArmPositionRight()pos2)*0.95);//fill the ()
                L().write(currentArmPositionRight()pos2);//fill the ()
                L().write((currentArmPositionRight()2*pos2)*1.1);//fill the ()
                currentArmPositionRight += pos2;
            }
        }
    }
}
void setup()
{
}
 
void loop()
{
armreach(60,200,1);
}