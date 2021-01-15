#pragma once



#include <player_data.hpp>
#include <object.hpp>



#define LEFT 0
#define RIGHT 1

#define STAND 2
#define JUMP 3
#define FALL 4

#define IDLE 5
#define MOVE 6

#define CHARACTER_REC { character::x, character::y, character::w, character::h }



class character {
private:
	object_manager& lvl;
	const int x_speed, y_speed;

public:
	character(const int x_speed, const int y_speed, object_manager& lvl) :
	x_speed(x_speed), y_speed(y_speed), lvl(lvl) { }
	~character() { }

	static int x, y, w, h;
	static player_data dir, action1, action2;

	friend void move_up(character* obj);
	friend void move_down(character* obj);
	friend void move_right(character* obj);
	friend void move_left(character* obj);

};