#include <Servo.h>

Servo L1;
Servo L2;
Servo L3;
Servo L4;
Servo L5;
Servo R1;
Servo R2;
Servo R3;
Servo R4;
Servo R5;

void pinout()
{

L3.attach(7);
L4.attach(10);
L5.attach(11);
R3.attach(4);
R4.attach(2);
R5.attach(3);
L1.attach(9);
L2.attach(8);
R1.attach(6);
R2.attach(5);
}

void startup()
{
L3.write(95);
L4.write(90);
L5.write(90);
R3.write(85);
R4.write(90);
R5.write(90);
L1.write(90);
L2.write(90);
R1.write(90);
R2.write(90);

}


void armreach(float toArmPosition, int sped, int armNum){//armNum:1(left).2:(right); to arm reach:90~30(90:the initial position,30:the furthest postion; speed:1/2/4)
    static float currentArmPositionLeft = 90;
    static float currentArmPositionRight = 90;
    static bool flag = true;
    float pos2 = 0.0625*sped;
    if(armNum == 1){
        if(currentArmPositionLeft > toArmPosition){
            if(!(millis()%20) && flag == true){
                currentArmPositionLeft -= pos2;
                L5.write(180-currentArmPositionLeft);
                L3.write(currentArmPositionLeft+5);
                L4.write(2.1*currentArmPositionLeft-99);
                flag = false;
            }
            if(millis()%50 != 0){
                flag = true;
            }
        }
        if(currentArmPositionLeft < toArmPosition){
            if(!(millis()%20) && flag == true){
              currentArmPositionLeft += pos2;
                L5.write(180-currentArmPositionLeft);
                L3.write(currentArmPositionLeft+5);
                L4.write(2.1*currentArmPositionLeft-99);
                flag = false;
            }
            if(millis()%50 != 0){
                flag = true;
            }
        }
    }
    if(armNum == 2){
        if(currentArmPositionLeft > toArmPosition){
            if(!(millis()%20) && flag == true){
                currentArmPositionLeft -= pos2;
                R5.write(180-currentArmPositionLeft);
                R3.write(180-currentArmPositionLeft-5);
                R4.write(2.1*currentArmPositionLeft-99);
                flag = false;
            }
            if(millis()%50 != 0){
                flag = true;
            }
        }
        if(currentArmPositionLeft < toArmPosition){
            if(!(millis()%20) && flag == true){
              currentArmPositionLeft += pos2;
                R5.write(180-currentArmPositionLeft);
                R3.write(180-currentArmPositionLeft-5);
                R4.write(2.1*currentArmPositionLeft-99);
                flag = false;
            }
            if(millis()%50 != 0){
                flag = true;
            }
        }
    }
    
}
void setup()
{
    pinout();
    startup();
    delay(2000);
}
 
void loop()
{  
  //L5.write(100);
  //delay(1500);
  //L5.write(90);
  //delay(1500);
  if(millis()<6000) armreach(70,2,2);// position,speed(1/2/4),armNum
  else armreach(90,4,2);






}
