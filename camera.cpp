#include "camera.hpp"
Camera::Camera(int _y) { y = _y - HEIGHT / 2; };
int Camera::get_y() { return y; }
void Camera::set_y(int new_y) { y = new_y - HEIGHT / 2; }
void Camera::show_map(Window* window, World_map& world, Character& character, const int& score) {
	window->clear();
	window->draw_img(ADDRESS_BACKGROUND);

	for (int object_count = 0; object_count < world.size(); object_count++)
	{
		if ((world[object_count]->get_y() <= y + HEIGHT))
		{
			world[object_count]->draw(y, window);
		}
	}
	character.draw(window, y);
	window->show_text("Point:", Point(15, 15), BLACK, ADDRESS_FONT, 35);
	window->show_text(to_string(score), Point(15, 50), BLACK, ADDRESS_FONT, 35);
	window->update_screen();
	return;
}
