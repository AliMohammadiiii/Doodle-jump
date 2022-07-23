#include "main.hpp"
int main() {
    int total_height = 0;
    int score = 0;
    Window *window = new Window(WIDTH, HEIGHT,  "Doodle Jump");
    World_map world;
	Sequences sequences = read_sequences();
	world = initialize_map(sequences, total_height);
    Character character((WIDTH-CHARACTER_WIDTH)/2,HEIGHT/2);
    Camera show_world(character.get_y());
    while(true){
        update(window, world, character, show_world, score, total_height, sequences);
        show_world.show_map(window, world, character, score);
        delay(15);
    }
    release(window,world,sequences,character,show_world);
	return 0;
}