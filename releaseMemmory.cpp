#include "releaseMemmory.hpp"
void release_object (World_map& world)
{
    for (int object_counter = 0; object_counter < world.size(); object_counter++)
    {
        world[object_counter]->~Object();
    }
}
void release_character(Character& character)
{
    character.~Character();
}

void release_window(Window* window)
{
    window->~Window();
}
void release(Window* window , World_map& world, Sequences& sequences , Character& character , Camera& camera)
{
    release_object(world);
    release_character(character);
    release_window(window);
}