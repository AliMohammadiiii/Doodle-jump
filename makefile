CC = g++ -std=c++11
EXE_FILE = doodleJump.out
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
&(EXE_FILE) : main.o rsdl.o createWorld.o object.o character.o camera.o update.o releaseMemmory.o
	$(CC) main.o rsdl.o createWorld.o object.o character.o camera.o update.o releaseMemmory.o $(CCFLAGS) -o $(EXE_FILE)

main.o: main.hpp src/rsdl.hpp createWorld.hpp object.hpp character.hpp camera.hpp releaseMemmory.hpp update.hpp main.cpp
	$(CC) -c main.cpp -o main.o

createWorld.o: createWorld.hpp object.hpp src/rsdl.hpp createWorld.cpp
	$(CC) -c createWorld.cpp -o createWorld.o

object.o: object.hpp src/rsdl.hpp object.cpp
	$(CC) -c object.cpp -o object.o

character.o: character.hpp object.hpp src/rsdl.hpp character.cpp
	$(CC) -c character.cpp -o character.o

camera.o: camera.hpp character.hpp object.hpp src/rsdl.hpp camera.cpp
	$(CC) -c camera.cpp -o camera.o

update.o: update.hpp camera.hpp character.hpp object.hpp src/rsdl.hpp update.cpp
	$(CC) -c update.cpp -o update.o

releaseMemmory.o: releaseMemmory.hpp camera.hpp character.hpp object.hpp src/rsdl.hpp releaseMemmory.cpp
	$(CC) -c releaseMemmory.cpp -o releaseMemmory.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

clean:
	rm *.o $(EXE_FILE)
