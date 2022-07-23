#include "object.hpp"

Animation::Animation(vector <string> address)
{
    images = address;
    time_show = 0;
    is_in_first_img = true;
    cursor = 0;
}
Animation::~Animation()
{
}
int Animation::get_cursor()
{ 
    return cursor; 
};
void Animation::set_time(int time)
{ 
    if (time == -1)
    {
        time = 2;
    }
    time_show = time;
};
void Animation::increase_cursor() 
{ 
    cursor++;
};
void Animation::decrease_time() { 
    time_show--;
};
int Animation::get_time() 
{
    return time_show;
};

string Animation::address_img(int img_cursor){
    if (img_cursor == -1)
    {
        return images[cursor];
    }
    else
    {
        return images[img_cursor];
    }
    
}

Object::Object(int _x, int _y, string _name, int _height, int _width, vector<string> address) {
    images = new Animation(address);
    x = _x;
    y = _y;
    name = _name;
    height = _height;
    width = _width;
    exist = true;
};
Object::~Object()
{
    images->~Animation();
}
bool Object::is_it_hit_me(int _x, int _y) {
    return ((_x - MOUSE_SIZE + CHARACTER_WIDTH / 2 >= x - width / 2) && (_x + MOUSE_SIZE - CHARACTER_WIDTH / 2 <= x + width / 2) && (_y >= y + height/2) && (_y <= y + height));
}
typedef vector < Object* > World_map;
string Object::what_am_i()
{
    return name;
};
void Object::increas_y(int height) 
{ 
    y += height;
};
int Object::get_y() 
{ 
    return y;
};
int Object::get_x() 
{ 
    return x;
};
void Object::kill() //if not worked write in hpp
{ 
    exist = false;
};
bool Object::am_i_exist() 
{ 
    return exist;
};



void Platform::draw(int camera_y, Window* window) {
    int show_y = HEIGHT + camera_y - y - height;
    int show_x = x - width / 2;
    window->draw_img(images->address_img(-1), Rectangle(show_x, show_y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
}

void Mplatform::horizental_move() {
    change_direction();
    if (go_right)
    {
        x += SPEED_MPLARFORM;
    }
    else
    {
        x -= SPEED_MPLARFORM;
    }
}
void Mplatform::change_direction() {
    if (x - (width / 2) - SPEED_MPLARFORM < 0 && !go_right)
    {
        go_right = true;
    }
    else if (x + (width / 2) + SPEED_MPLARFORM > WIDTH && go_right)
    {
        go_right = false;
    }
}
void Mplatform::draw(int camera_y, Window* window) {
    int show_y = HEIGHT + camera_y - y - height;
    int show_x = x - PLATFORM_WIDTH / 2;
    window->draw_img(images->address_img(-1), Rectangle(show_x, show_y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
}


void Bplatform::break_platform() {
    is_break = true;
}
void Bplatform::update() {
    if (is_break)
    {
        if (images->get_time() <= 0 && images->get_cursor() != 3)
        {
            images->increase_cursor();
            images->set_time(-1);
        }
        y -= SPEED_HORIZENTAL;
        images->decrease_time();
    }

}
void Bplatform::draw(int camera_y, Window* window) {
    int show_y = HEIGHT + camera_y - y - height;
    int show_x = x - PLATFORM_WIDTH / 2;
    window->draw_img(images->address_img(-1), Rectangle(show_x, show_y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
}

void Spring::draw(int camera_y, Window* window) {
    int show_y = HEIGHT + camera_y - y - height;
    int show_x = x - SPRING_WIDTH / 2;
    window->draw_img(images->address_img(-1), Rectangle(show_x, show_y, SPRING_WIDTH, SPRING_HEIGHT));
}

bool Enemy::is_it_hit_me(int _x, int _y) {
    return ((_x - MOUSE_SIZE + CHARACTER_WIDTH / 2 >= x - width / 2) && (_x + MOUSE_SIZE - CHARACTER_WIDTH / 2 <= x + width / 2) && ((_y + CHARACTER_HEIGHT) >= y) && (_y <= y + height));
}
void Enemy::draw(int camera_y, Window* window) {
    int show_y = HEIGHT + camera_y - y - height;
    int show_x = x - ENEMY_WIDTH / 2;
    window->draw_img(images->address_img(-1), Rectangle(show_x, show_y, ENEMY_WIDTH, ENEMY_HEIGHT));
}