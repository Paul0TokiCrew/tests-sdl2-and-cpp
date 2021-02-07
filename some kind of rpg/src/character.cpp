#include <character.hpp>



int character::x = 0, character::y = 0,
	character::w = 0, character::h = 0;

player_data character::dir = player_data(UP, LEFT),
	character::action = player_data(IDLE, MOVE);



void move_up(character* obj, const float delta_time) {
	character::y += obj->speed * delta_time;

}

void move_down(character* obj, const float delta_time) {
	character::y += obj->speed * delta_time;

}

void move_right(character* obj, const float delta_time) {
	character::x += obj->speed * delta_time;

}

void move_left(character* obj, const float delta_time) {
	character::x += obj->speed * delta_time;

}