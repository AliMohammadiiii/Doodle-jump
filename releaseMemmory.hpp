#ifndef releaseMemmory_hpp_
#define releaseMemmory_hpp_
#include "general.hpp"
#include "object.hpp"
#include "character.hpp"
#include "camera.hpp"
void release_object (World_map& world);
void release_character(Character& character);
void release_window(Window* window);
void release(Window* window , World_map& world, Sequences& sequences , Character& character , Camera& camera);
#endif