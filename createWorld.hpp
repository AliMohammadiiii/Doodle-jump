#ifndef createWorld_hpp_
#define createWorld_hpp_
#include "object.hpp"
void add_to_sequeces(Object* object, Sequences& sequences, ifstream& static_map, int object_counter);
Sequences read_sequences();
vector <int> which_one_are_in_range(int point, Sequences& sequences, int end_point);
Object* new_object_set(Object* old_object);
World_map initialize_map(Sequences& sequences, int& total_height);
void world_update(Sequences& sequences, World_map& world, int score, int& total_height);
#endif