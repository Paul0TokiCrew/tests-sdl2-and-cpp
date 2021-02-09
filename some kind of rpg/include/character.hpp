#pragma once



#include <SDL2/SDL.h>
#include <vec2f.hpp>
#include <player_data.hpp>
#include <object.hpp>



#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define IDLE 4
#define MOVE 5

#define CHARACTER_REC { character::x, character::y, character::w, character::h }



class character {
private:
	int speed;

public:
	character() { }
	constexpr character(const int speed) :
	speed(speed) { }
	~character() { }

	static vec2f pos;
	static int w, h;
	static player_data dir, action;

	void set_speed(const int new_speed) { this->speed = new_speed; }
	int get_speed() const { return this->speed; }

	friend void move_up(character* obj, const float delta_time);
	friend void move_down(character* obj, const float delta_time);
	friend void move_right(character* obj, const float delta_time);
	friend void move_left(character* obj, const float delta_time);

};