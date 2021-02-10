#include <character.hpp>



vec2f character::pos = vec2f(0, 0);
int character::w = 0, character::h = 0;

player_data character::y_dir = player_data(UP, DOWN),
	character::x_dir = player_data(RIGHT, LEFT),
	character::action = player_data(IDLE, MOVE);



void move_up(character* obj, const float delta_time) {
	character::pos.y += obj->speed * delta_time;

}

void move_down(character* obj, const float delta_time) {
	character::pos.y += obj->speed * delta_time;

}

void move_right(character* obj, const float delta_time) {
	character::pos.x += obj->speed * delta_time;

}

void move_left(character* obj, const float delta_time) {
	character::pos.x += obj->speed * delta_time;

}