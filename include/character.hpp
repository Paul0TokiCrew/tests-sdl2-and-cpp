#pragma once



#include <player_data.hpp>



#define LEFT 0
#define RIGHT 1

#define STAND 2
#define JUMP 3
#define FALL 4

#define IDLE 5
#define MOVE 6



class character {
public:
	character() { }
	~character() { }

	static int x, y, w, h;
	static player_data dir, action1, action2;

	static void move_up();
	static void move_down();
	static void move_right();
	static void move_left();

};