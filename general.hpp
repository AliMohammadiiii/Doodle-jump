#ifndef general_hpp_
#define general_hpp_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<time.h>
#include <sstream>
#include "src/rsdl.hpp"
using namespace std;


#define WIDTH 640
#define HEIGHT 1024
#define PLATFORM_WIDTH 120
#define PLATFORM_HEIGHT 36
#define ENEMY_WIDTH 136
#define ENEMY_HEIGHT 184
#define CHARACTER_WIDTH 124
#define CHARACTER_HEIGHT 120
#define SPRING_WIDTH 56
#define SPRING_HEIGHT 46
#define ADDRESS_DYNAMIC_MAP "sequence.txt"
#define ADDRESS_MAP "./sample_map/static/map.txt"
#define ADDRESS_BACKGROUND "./assets/background.png"
#define ADDRESS_BPLATFORM1 "./assets/Broken1.png"
#define ADDRESS_BPLATFORM2 "./assets/Broken2.png"
#define ADDRESS_BPLATFORM3 "./assets/Broken3.png"
#define ADDRESS_BPLATFORM4 "./assets/Broken4.png"
#define ADDRESS_LEFT_JUMPING "./assets/left_jumping.png"
#define ADDRESS_LEFT "./assets/left.png"
#define ADDRESS_ENEMY "./assets/monster.png"
#define ADDRESS_RIGHT "./assets/right.png"
#define ADDRESS_RIGHT_JUMPING "./assets/right_jumping.png"
#define ADDRESS_PLATFORM "./assets/simple.png"
#define ADDRESS_MPLATFORM "./assets/mplatform.png"
#define ADDRESS_SPRING "./assets/spring.png"
#define ADDRESS_FONT "./assets/SnowyNight.ttf"
#define NUMBER_FRAME_JUMP 7
#define JUMP_TIME 55
#define INCREASE_SPEED_JUMP VERTICAL_SPEED_CHARACTER
#define VERTICAL_SPEED_CHARACTER 10
#define SPEED_HORIZENTAL 10
#define SPEED_MPLARFORM  5
#define MOUSE_SIZE 15
#define KEY_LEFT 'a'
#define KEY_LEFT_CAPITAL 'A'
#define KEY_RIGHT 'd'
#define KEY_RIGHT_CAPITAL 'D'
#endif