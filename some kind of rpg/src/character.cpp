#include <character.hpp>



int character::x = 0, character::y = 0,
	character::w = 0, character::h = 0;

player_data character::dir = player_data(UP, LEFT),
	character::action = player_data(IDLE, MOVE);



void move_up(character* obj, const float delta_time) {
	if (obj->obj_man.check_up_collision(CHARACTER_REC))
		return;
	character::y += obj->speed * delta_time;

}

void move_down(character* obj, const float delta_time) {
	if (obj->obj_man.check_down_collision(CHARACTER_REC))
		return;
	character::y += obj->speed * delta_time;

}

void move_right(character* obj, const float delta_time) {
	if (obj->obj_man.check_right_collision(CHARACTER_REC))
		return;
	character::x += obj->speed * delta_time;

}

void move_left(character* obj, const float delta_time) {
	if (obj->obj_man.check_left_collision(CHARACTER_REC))
		return;
	character::x += obj->speed * delta_time;

}