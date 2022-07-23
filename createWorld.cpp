#include "createWorld.hpp"
void add_to_sequeces(Object* object, Sequences& sequences, ifstream& static_map, int object_counter)
{
	string line = "", object_name = "";
	int x , y;
	getline(static_map, line);
	stringstream separate(line);
	separate >> x >> y >> object_name;
	if (object_name == "platform")
	{
		object = new Platform(x, y);
		sequences[object_counter].objects.push_back(object);
	}
	else if (object_name == "bplatform")
	{
		object = new Bplatform(x, y);
		sequences[object_counter].objects.push_back(object);
	}
	else if (object_name == "mplatform")
	{
		object = new Mplatform(x, y);
		sequences[object_counter].objects.push_back(object);
	}
	else if (object_name == "spring")
	{
		object = new Spring(x, y);
		sequences[object_counter].objects.push_back(object);
	}
	else if (object_name == "enemy")
	{
		object = new Enemy(x, y);
		sequences[object_counter].objects.push_back(object);
	}
}
Sequences read_sequences()
{
	ifstream static_map(ADDRESS_DYNAMIC_MAP);
	string line = "", object_name = "";
	int number_of_sequences = 0;
	getline(static_map, line);
	number_of_sequences = stoi(line);
	Sequences sequences(number_of_sequences);
	int x = 0, y = 0;
	Object* object;
	for (int object_counter = 0; object_counter < number_of_sequences; object_counter++)
	{
		string line = "", object_name = "";
		int number_of_entities = 0;
		getline(static_map, line);
		if (line == "")
		{
			object_counter--;
			continue;
		}
		stringstream separate(line);
		separate >> sequences[object_counter].start_point >> sequences[object_counter].end_point >> sequences[object_counter].total_height_sequence >> sequences[object_counter].number_of_enetities;
		int x = 0, y = 0;
		Object* object;
		for (int entities_counter = 0; entities_counter < sequences[object_counter].number_of_enetities; entities_counter++)
		{
			add_to_sequeces(object,sequences,static_map,object_counter);
		}
	}
	return sequences;
}
vector <int> which_one_are_in_range(int point, Sequences& sequences, int end_point = HEIGHT) {
	vector <int> number_sequence_available;
	for (int sequence_counter = 0; sequence_counter < sequences.size(); sequence_counter++)
	{
		if (sequences[sequence_counter].start_point <= (point + end_point) && (sequences[sequence_counter].end_point >= (point + end_point) || sequences[sequence_counter].end_point == -1))
		{
			number_sequence_available.push_back(sequence_counter);
		}
	}
	return number_sequence_available;
}
Object* new_object_set(Object* old_object){
	Object* object;
    if (old_object->what_am_i() == "platform")
    {
        object = new Platform(old_object->get_x(), old_object->get_y());
    }
    else if (old_object->what_am_i() == "bplatform")
    {
        object = new Bplatform(old_object->get_x(), old_object->get_y());
    }
    else if (old_object->what_am_i() == "mplatform")
	{
	    object = new Mplatform(old_object->get_x(), old_object->get_y());
	}
	else if (old_object->what_am_i() == "spring")
	{
	    object = new Spring(old_object->get_x(), old_object->get_y());
	}
	else if (old_object->what_am_i() == "enemy")
	{
		object = new Enemy(old_object->get_x(), old_object->get_y());
	}
    return object;
}
World_map initialize_map(Sequences& sequences, int& total_height) {
	World_map world;
	vector <int> number_sequence_available;
    Object* new_object;
	number_sequence_available = which_one_are_in_range(0, sequences, 0);
	srand(time(0));
	int rand_number_sequence = number_sequence_available[rand() % number_sequence_available.size()];
	for (int object_counter = 0; object_counter < sequences[rand_number_sequence].objects.size(); object_counter++)
	{
		world.push_back(sequences[rand_number_sequence].objects[object_counter]);
	}
	total_height += sequences[rand_number_sequence].total_height_sequence;
	while (total_height < (3*HEIGHT)/2)
	{
		number_sequence_available = which_one_are_in_range(total_height, sequences, 0);
		srand(time(0));
		int rand_number_sequence = number_sequence_available[rand() % number_sequence_available.size()];
		for (int object_counter = 0; object_counter < sequences[rand_number_sequence].objects.size(); object_counter++)
		{
            
            new_object = new_object_set(sequences[rand_number_sequence].objects[object_counter]);
			world.push_back(new_object);
			world[world.size() - 1]->increas_y(total_height);
		}
		total_height += sequences[rand_number_sequence].total_height_sequence;
	}
	return world;
}
void world_update(Sequences& sequences, World_map& world, int score, int& total_height)
{
    Object* new_object;
	vector <int> number_sequence_available = which_one_are_in_range(total_height, sequences);
	srand(time(0));
	int rand_number_sequence = number_sequence_available[rand() % number_sequence_available.size()];
	for (int object_counter = 0; object_counter < sequences[rand_number_sequence].objects.size(); object_counter++)
	{
		new_object = new_object_set(sequences[rand_number_sequence].objects[object_counter]);
		world.push_back(new_object);
		world[world.size() - 1]->increas_y(total_height);
	}
	total_height += sequences[rand_number_sequence].total_height_sequence;
}