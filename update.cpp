#include "update.hpp"
void end_game(Window *window, int& point, World_map& world, Character& character, Camera& camera, Sequences& sequences){
    window->clear();
    window->draw_img(ADDRESS_BACKGROUND);
    window->show_text("Game Over:",Point(180,450),BLACK,ADDRESS_FONT,60);
    window->show_text(to_string(point),Point(270,520),BLACK,ADDRESS_FONT,60);
    window->update_screen();
    while (true)
    {
        Event e = window->poll_for_event();
        if (e.get_type() == Event::KEY_PRESS || e.get_type() == Event::EventType::QUIT)
        {
            release(window,world,sequences,character,camera);
            exit(0);
        }
    }
}

void event_handeling(Window *window , Character& character, World_map& world, Sequences& sequences, Camera& camera)
{
    Event e = window->poll_for_event();
        if (e.get_type() == Event::KEY_RELEASE)
        {
            character.change_state_press(false);
        }
        switch (e.get_type())
        {
        case Event::EventType::QUIT:
            release(window,world,sequences,character,camera);
            exit(0);
            break;
        case Event::KEY_PRESS:
            char pressed_char = e.get_pressed_key();
            character.set_direction(pressed_char);
            if (pressed_char == 'a'|| pressed_char == 'A' || pressed_char == 'd' || pressed_char == 'D')
                character.change_state_press(true);
        break;
        }
}
bool should_the_game_end(Character& character,Camera& camera)
{
    return (character.get_y() + CHARACTER_HEIGHT <= camera.get_y());
}
bool should_the_world_generate(int& score, int& total_height)
{
    return (total_height - score < HEIGHT);
}
void set_camera_and_score (Character& character,Camera& camera, int& score)
{
    if (character.am_i_upper_mid(camera.get_y()))
    {
        score += (character.get_y()-camera.get_y()-(HEIGHT/2));
        camera.set_y(character.get_y());
    }
}
void platform_hit(Window* window, World_map& world, Character& character,int x, int y, int object_conter, int score , Camera& camera, Sequences& sequences)
{
    if (world[object_conter]->is_it_hit_me(x,y) && !character.get_jump_state())
        {
            if (world[object_conter]->what_am_i() == "bplatform")
            {
                Bplatform* broken = (Bplatform*)world[object_conter];
                broken->break_platform();
                return;
            }
            if (world[object_conter]->what_am_i() == "spring")
            {
                character.add_extra_time_jump();
            }
            character.change_jump_state();
        }
        if (world[object_conter]->is_it_hit_me(x,y)&&world[object_conter]->what_am_i() == "enemy")
        {
            end_game(window,score, world, character, camera , sequences);
        }
}

void platform_update(World_map& world , int object_conter)
{
    if (world[object_conter]->what_am_i() == "mplatform")
    {
        Mplatform* move = (Mplatform*)world[object_conter];
        move->horizental_move();
    }
    if (world[object_conter]->what_am_i() == "bplatform")
    {
        Bplatform* broken = (Bplatform*)world[object_conter];
        broken->update();
    }
}
bool is_platform_under_camera (World_map& world , Camera& camera , int object_conter)
{
    return (world[object_conter]->get_y() < camera.get_y() && world[object_conter]->what_am_i() != "bplatform");
}
void update(Window *window , World_map& world, Character& character,Camera& camera, int& score, int& total_height, Sequences& sequences){
    if (should_the_game_end(character, camera))
    {
        end_game(window,score , world, character,camera,sequences);
    }
    while (should_the_world_generate(score, total_height))
	{
		world_update(sequences, world, score, total_height);
	}
    set_camera_and_score(character,camera, score);
    if(window->has_pending_event())
    {
        event_handeling(window, character, world, sequences, camera);
    }
    character.update(camera.get_y());
    int x = character.get_x();
    int y = character.get_y();
    int must_erase = 0;
    for (int object_conter = 0; object_conter < world.size(); object_conter++)
    {
        if (is_platform_under_camera(world , camera , object_conter))
        {
           must_erase++;
        }
        platform_hit(window,world,character,x,y,object_conter,score,camera,sequences);
        platform_update(world,object_conter);
    }
    for (int i = 0; i < must_erase; i++)
    {
        world.erase(world.begin());
    }
    
}