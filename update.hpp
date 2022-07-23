#ifndef update_hpp_
#define update_hpp_
#include "createWorld.hpp"
#include "object.hpp"
#include "character.hpp"
#include "camera.hpp"
#include "releaseMemmory.hpp"
void end_game(Window *window, int& point, World_map& world, Character& character, Camera& camera, Sequences& sequences);
void event_handeling(Window *window , Character& character, World_map& world, Sequences& sequences, Camera& camera);
bool should_the_game_end(Character& character,Camera& camera);
bool should_the_world_generate(int& score, int& total_height);
void set_camera_and_score (Character& character,Camera& camera, int& score);
void platform_hit(Window* window, World_map& world, Character& character,int x, int y, int object_conter, int score, Camera& camera, Sequences& sequences);
void platform_update(World_map& world , int object_conter);
bool is_platform_under_camera (World_map& world , Camera& camera , int object_conter);
void update(Window *window , World_map& world, Character& character,Camera& camera, int& score, int& total_height, Sequences& sequences);
#endif