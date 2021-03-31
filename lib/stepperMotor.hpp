//
// Created by Administrator on 2021/4/1.
//
#ifndef stepMotor
#define stepMotor

#define stepperMotor_n 6
//                      l_L, l_R, r_L, r_R, h_1, h_2
const int ConstPul[] = {28,  13,  33,  12,  11,  10};
const int ConstDir[] = {13,  17,  20,  23,  41,  45};

struct _stepperMotor{
    int id, counter, pul, dir, current_dir;//current_dir: 0->无方向, counter: 计数器
    unsigned long int time;
    float current_position;//current_position继承了angle与position,命名为position

    _stepperMotor() = default;
    void reload(int id){
        this->id = id;
        this->counter = 1;
        this->pul = ConstPul[this->id];
        this->dir = ConstDir[this->id];
        this->current_dir = 0;
        this->time = micros();
        this->current_position = 0.0;
    }

    void rotate(float to_angle){
        if (to_angle == this->current_position){
            this->counter = 1;
            this->current_dir = 0;
            return;
        }
        int to_dir = to_angle - this->current_position > 0 ? 1 : -1;
        if (this->current_dir != to_dir){
            digitalWrite(this->pul, 0);
            if((micros() - this->time) > 1000000){
                this->current_dir = to_dir;
                this->time = micros();
            }
        }
        else{
            digitalWrite(this->dir, (to_dir + 1) / 2);//to_dir = 1, val = 1; to_dir = -1, val = 0
            this->current_dir = (to_dir + 1) / 2;
            if((micros() - this->time) >= 250){
                digitalWrite(pul, this->counter%2);
                this->current_position = this->current_position + to_dir * (this->counter%2 == 1)*0.225;
                this->counter += 1;
                this->time = micros();
            }
        }
    }
}stepperMotor[stepperMotor_n];

#endif