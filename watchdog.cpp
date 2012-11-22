#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <stdlib.h>
#include "robot.h"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int r1_initial_position, r2_initial_position;

bool check_other_init_position(int my_id,int my_curent_position, bool direction)
{
    int other_init_position = (my_id == 1) ? r2_initial_position : r1_initial_position;
    return ( my_curent_position == other_init_position) ? true : false;
}

int main()
{
    const int initial_step = 1, my_id_1 = 1, my_id_2 = 2;
    const bool direction = false;
    
    Robot *r1, *r2;

    //Position the two robots in random different positions 
    srand(time(0));
    r1_initial_position = rand() % 300;
    r2_initial_position = rand() % 300;
    
    r1 = new Robot(my_id_1, initial_step, r1_initial_position, direction);
    r2 = new Robot(my_id_2, initial_step, r2_initial_position, direction);

    cout << "r1 :" << r1->get_initial_position() << endl;
    cout << "r2 :" << r2->get_initial_position() << endl;
    
    //The child process will run the robot r1, the parnt will run r2
    int pid = fork();
    if ( pid == 0 ) r1->move(check_other_init_position);
    else r2->move(check_other_init_position);

    delete(r1);
    delete(r2);
}
