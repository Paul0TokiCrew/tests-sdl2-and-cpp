#pragma once



#include <SDL2/SDL.h>
#include <player_data.hpp>
#include <object.hpp>



#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define IDLE 4
#define MOVE 5

#define CHARACTER_REC { std::ceil(character::x), std::ceil(character::y), std::ceil(character::w), std::ceil(character::h) }



class character {
private:
	int speed;
	object_manager& obj_man;

public:
	character() { }
	constexpr character(const int speed, object_manager& obj_man) :
	speed(speed), obj_man(obj_man) { }
	~character() { }

	static int x, y, w, h;
	static player_data dir, action;

	void set_speed(const int new_speed) { this->speed = new_speed; }
	int get_speed() const { return this->speed; }

	friend void move_up(character* obj, const float delta_time);
	friend void move_down(character* obj, const float delta_time);
	friend void move_right(character* obj, const float delta_time);
	friend void move_left(character* obj, const float delta_time);

};