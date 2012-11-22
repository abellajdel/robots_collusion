#include "robot.h"
#include <iostream>
using namespace std;

Robot::Robot(int _my_id, int _step, int _initial_position, bool _direction)
{
    my_id = _my_id;
    step = _step;
    initial_position = _initial_position;
    curent_position = initial_position;
    direction = _direction;
    other_initial_position_passed = false;
}

void Robot::move_one_step(void)
{
    if(direction) curent_position += step;
    else curent_position -= step;
}

//void Robot::move(bool (*check_other_init_position)(int,int,bool), bool (*collided)(int,int,bool))
void Robot::move(bool (*check_other_init_position)(int,int,bool))
{
    while(true)
    {
        move_one_step();
        sleep(1); 
        cout << "I'm " << my_id << " and my position is " << curent_position << endl;
        if(!other_initial_position_passed && 
              (*check_other_init_position)(my_id, curent_position, direction))
        {
            speed_up(1);
            other_initial_position_passed = true;
            cout << "I'm " << my_id << " and I passed the other robot initial position and speeded up" << endl;
        }
        /*else if(other_initial_position_passed == true)
        {
            if((*collided)(curent_position, direction))
            {
                cout << "I collided with the other robot" << endl;
                break;
            }
        }*/
    }
}

void Robot::speed_up(int increase)
{
    step += increase;
}

int Robot::get_step()
{
    return step;
}

int Robot::get_curent_position()
{
    return curent_position;
}

int Robot::get_initial_position()
{
    return initial_position;
}

bool Robot::get_direction()
{
    return direction;
}

bool Robot::get_other_initial_position_passed()
{
    return other_initial_position_passed;
}
