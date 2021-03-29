#define dir_r_r 21
#define pul_r_r 22

int i = 1;
int current_right_ange;

struct 
{
    int part;
    int movement;
    int position;
} piinf;

void setup()
{
    Serial.begin(9600);
    pinMode(dir_r_r, OUTPUT);
    pinMode(pul_r_r, OUTPUT);
    piinf.part = 0;
    piinf.movement = 0;
    piinf.position = 0;
    
}
void steppermotor_right_rotate(int to_angle)
{
    static int to_dir;
    if(to_angle - current_right_ange > 0) to_dir = 1;
    if(to_angle - current_right_ange < 0) to_dir = 0;
    static int current_dir = to_dir;
    static unsigned long time = 0;
    if(current_dir != to_dir && current_dir != -1)
    {
        digitalWrite(pul_r_r, 0);
        if((micros()-time) > 1000000)
        {
            current_dir = to_dir;
            time = micros();
        }
    }
    else
    {
        if(to_dir == 1)
        {
        
            digitalWrite(dir_r_r, 1);
            current_dir = 1;
            if((micros() - time) >= 150)
            {
                digitalWrite(pul_r_r, i%2);
                current_right_ange = current_right_ange + (i%2 == 1)*0.225;
                i += 1;
                time = micros();
            } 
        }
        if(to_dir == 0)
        {
            digitalWrite(dir_r_r, 0);
            current_dir = 0;
            if((micros() - time) >= 150)
            {
                digitalWrite(pul_r_r, i%2);
                current_right_ange = current_right_ange - (i%2 == 1)*0.225;
                i += 1;
                time = micros();
            } 
        }
        if(to_angle-current_right_ange == 0)
        {
            i = 1;
            current_dir = -1;//此时方向为任意
        }
    }

}

void loop()
{
    //收到pi传来的信息（第一位2指右臂，第二位1指旋转，第三位90指旋转移动到的位置)
    piinf.part = 2;
    piinf.movement = 1;
    piinf.position = 5*700;

    if(piinf.part == 2)
    {
        if(piinf.movement == 1)
        {
            steppermotor_right_rotate(piinf.position);//from 0 to 25*700 (700 steps per cm),一般不输入负数，负数用于测试后的归正
        }
    }
}