#ifndef camera_hpp_
#define camera_hpp_
#include "general.hpp"
#include "object.hpp"
#include "character.hpp"
class Camera
{
public:
	Camera(int _y);
	void set_y(int new_y);
	int get_y();
	void show_map(Window* window, World_map& world, Character& character, const int& score);
private:
	int y;
};
#endif