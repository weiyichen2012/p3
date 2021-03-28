#include <Servo.h>
#define PIN_SERVO 10
Servo myservo;
 
void setup()
{
  myservo.attach(3);
}
 
void loop()
{
myservo.write(90);
}