#ifndef object_hpp_
#define object_hpp_
#include "general.hpp"
class Animation
{
private:
    vector < string > images;
    int time_show;
    bool is_in_first_img;
    int cursor;
public:
    Animation(vector <string> address);
    ~Animation();
    void set_time(int time);
    int get_cursor();
    void increase_cursor();
    string address_img(int img_cursor);
    int get_time();
    void decrease_time();
};

class Object
{
public:
    Object(int _x, int _y, string _name, int _height, int _width, vector<string> address);
    ~Object();
    virtual void update() {};
    virtual void draw(int camera_y, Window* window) {};
    string what_am_i();
    virtual bool is_it_hit_me(int _x, int _y);
    void increas_y(int height);
    int get_y();
    int get_x();
    virtual void kill();
    bool am_i_exist();
protected:
    int x;
    int y;
    Animation* images;
    string name;
    int height;
    int width;
    bool exist;
};
typedef vector < Object* > World_map;
struct Sequence
{
	vector <Object*> objects;
	int start_point;
	int end_point;
	int total_height_sequence;
	int number_of_enetities;
};
typedef vector < Sequence > Sequences;
class Platform : public Object
{
public:
    Platform(int _x, int _y)
        :Object(_x, _y, "platform", PLATFORM_HEIGHT, PLATFORM_WIDTH, { ADDRESS_PLATFORM }) {};
    virtual void draw(int camera_y, Window* window);
private:

};

class Mplatform : public Object
{
public:
    Mplatform(int _x, int _y)
        :Object(_x, _y, "mplatform", PLATFORM_HEIGHT, PLATFORM_WIDTH, { ADDRESS_MPLATFORM }) {
        go_right = true;
    };
    virtual void draw(int camera_y, Window* window);
    void horizental_move();
    void change_direction();
private:
    bool go_right;
};


class Bplatform : public Object
{
public:
    Bplatform(int _x, int _y)
        :Object(_x, _y, "bplatform", PLATFORM_HEIGHT, PLATFORM_WIDTH, { ADDRESS_BPLATFORM1,ADDRESS_BPLATFORM2,ADDRESS_BPLATFORM3,ADDRESS_BPLATFORM4 }) {
        is_break = false;
    };
    virtual void draw(int camera_y, Window* window);
    void break_platform();
    void update();
private:
    bool is_break;
    string img_address;
};

class Spring : public Object
{
public:
    Spring(int _x, int _y)
        :Object(_x, _y, "spring", SPRING_HEIGHT, SPRING_WIDTH, { ADDRESS_SPRING }) {};
    virtual void draw(int camera_y, Window* window);
private:

};

class Enemy : public Object
{
public:
    Enemy(int _x, int _y)
        :Object(_x, _y, "enemy", ENEMY_HEIGHT, ENEMY_WIDTH, { ADDRESS_ENEMY }) {};
    virtual bool is_it_hit_me(int _x, int _y);
    virtual void draw(int camera_y, Window* window);
private:

};
#endif