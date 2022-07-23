#include "character.hpp"
Character::Character(int _x, int _y) {
    image = new Animation({ ADDRESS_LEFT,ADDRESS_LEFT_JUMPING,ADDRESS_RIGHT,ADDRESS_RIGHT_JUMPING });
    is_left = false;
    x = _x;
    y = _y;
    in_jump = false;
    time_in_jump = 0;
    is_press = false;
    can_i_jump_again = true;
    jump_step = false;
    spring_jump = false;
    speed = 0;
}
Character::~Character()
{
    image->~Animation();
}
void Character::decrease_speed()
{
    speed -= GRAVITY; 

}

void Character::set_speed(int initialize_speed)
{

    speed = initialize_speed;

}

int Character::get_y()
{
    return y;
}
int Character::get_x()
{
    return x;
}
void Character::change_state_press(bool state)
{
    is_press = state;
}
void Character::add_extra_time_jump()
{
    spring_jump = true;
}
bool Character::get_jump_state()
{
    return in_jump;
}
void Character::change_jump_step(bool step)
{
    jump_step = step;
}
void Character::can_i_jump() {
    if (speed < -1)
    {
        can_i_jump_again = true;
    }

}
void Character::change_jump_state() {
    if (can_i_jump_again)
    {
        time_in_jump = JUMP_TIME;
        in_jump = true;
        can_i_jump_again = false;
        jump_step = true;
        image->set_time(NUMBER_FRAME_JUMP);
        if (spring_jump)
        {
            set_speed (2 * VERTICAL_SPEED_CHARACTER);
        }
        else
        {
            set_speed (VERTICAL_SPEED_CHARACTER);
        }
        
    }
}
bool Character::am_i_upper_mid(int camera_y) {
    return ((y - camera_y) > (HEIGHT / 2));
}
void Character::set_direction(char direction) {
    if (direction == KEY_LEFT || direction == KEY_LEFT_CAPITAL)
    {
        is_left = true;
    }
    else if (direction == KEY_RIGHT || direction == KEY_RIGHT_CAPITAL)
    {
        is_left = false;
    }
}
void Character::draw(Window* window, int camera_y) {
    int address_img;
    if (is_left)
    {
        address_img = 0;
    }
    else
    {
        address_img = 2;
    }
    int show_y = HEIGHT + camera_y - y - CHARACTER_HEIGHT;
    int show_x = x - CHARACTER_WIDTH / 2;
    if (jump_step)
    {
        window->draw_img(image->address_img(address_img + 1), Rectangle(show_x, show_y, CHARACTER_WIDTH, CHARACTER_HEIGHT));
    }
    else
    {
        window->draw_img(image->address_img(address_img), Rectangle(show_x, show_y, CHARACTER_WIDTH, CHARACTER_HEIGHT));
    }
}
void Character::vertical_move() {
    if (time_in_jump <= 0)
    {
        in_jump = false;
        spring_jump = false;
    }
    decrease_speed();
    y += speed;
    time_in_jump--;
}
string Character::am_i_in_screan(int camera_y) {
    if ((y + CHARACTER_HEIGHT) <= camera_y)
    {
        return "down";
    }
    else if (y >= (camera_y + HEIGHT))
    {
        return "up";
    }
    if (x < 0)
    {
        return "left";
    }
    else if (x > WIDTH)
    {
        return "right";
    }
    return "inside";
}
void Character::back_to_screen() {
    if (am_i_in_screan(y) == "left")
    {
        x = WIDTH;
    }
    if (am_i_in_screan(y) == "right")
    {
        x = 0;
    }
}
void Character::update(int camera_y) {
    if (image->get_time() <= 0)
    {
        jump_step = false;
    }
    can_i_jump();
    if (!is_left && is_press)
    {
        x += SPEED_HORIZENTAL;
    }
    else if (is_left && is_press)
    {
        x -= SPEED_HORIZENTAL;
    }
    back_to_screen();
    vertical_move();
    image->decrease_time();
}

