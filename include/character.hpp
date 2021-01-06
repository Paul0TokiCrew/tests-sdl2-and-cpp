#pragma once



#include <player_data.hpp>



class character {
public:
	character() { }
	~character() { }

	static int x, y, w, h;
	static void move_up();
	static void move_down();
	static void move_right();
	static void move_left();

};