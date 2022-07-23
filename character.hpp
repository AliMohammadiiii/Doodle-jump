#ifndef character_hpp_
#define character_hpp_
#include "object.hpp"
#include "general.hpp"
#define GRAVITY 0.2
class Character
{
public:
    Character(int _x, int _y);
    ~Character();
    void update(int camera_y);
    void draw(Window* window, int camera_y);
    void vertical_move();
    void set_direction(char direction);
    int get_y();
    int get_x();
    bool am_i_upper_mid(int camera_y);
    void back_to_screen();
    string am_i_in_screan(int camera_y);
    void change_state_press(bool state);
    void change_jump_state();
    void add_extra_time_jump();
    bool get_jump_state();
    void can_i_jump();
    void change_jump_step(bool step);
    void set_speed(int initialize_speed);
    void decrease_speed();
private:
    Animation* image;
    int x;
    int y;
    bool is_left;
    bool in_jump;
    int time_in_jump;
    bool is_press;
    bool can_i_jump_again;
    bool jump_step;
    bool spring_jump;
    float speed;
};
#endif