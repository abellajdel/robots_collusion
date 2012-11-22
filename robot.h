/*
 * In this robot colusion game, we assume that 
 * step is jumped in constant time: an increase in step
 * results automatically in an increase in speed
 */

class Robot{
  private:
    int my_id, step, curent_position, initial_position;
    bool direction, other_initial_position_passed;

  public:
    Robot(int, int, int, bool);
    void move_one_step(void);
    //void move(bool (*check_other_init_position)(int,int,bool), bool (*collided)(int,int,bool));
    void move(bool (*check_other_init_position)(int,int,bool));
    void speed_up(int);

    int get_step();
    int get_curent_position();
    int get_initial_position();
    bool get_direction();
    bool get_other_initial_position_passed();
    
    void set_other_initial_position_passed(bool);
};
