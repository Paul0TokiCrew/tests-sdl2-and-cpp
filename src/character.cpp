#include <character.hpp>



int character::x = 0, character::y = 0,
	character::w = 80, character::h = 80,
	character::jump_count = 0;

player_data character::dir = player_data(LEFT, RIGHT),
	character::action1 = player_data(STAND, FALL),
	character::action2 = player_data(IDLE, MOVE);



void move_up(character* obj, float time_step) {

	for (int i = 0; i < std::ceil(obj->y_speed * time_step); ++i)
		if (obj->lvl.check_up_collision(CHARACTER_REC))
			break;

		else
			--character::y;

}

void move_down(character* obj, float time_step) {

	for (int i = 0; i < std::ceil(obj->y_speed * time_step); ++i)
		if (obj->lvl.check_down_collision(CHARACTER_REC))
			break;

		else
			++character::y;

}

void move_right(character* obj, float time_step) {

	for (int i = 0; i < std::ceil(obj->x_speed * time_step); ++i)
		if (obj->lvl.check_right_collision(CHARACTER_REC))
			break;

		else
			++character::x;

}

void move_left(character* obj, float time_step) {

	for (int i = 0; i < std::ceil(obj->x_speed * time_step); ++i)
		if (obj->lvl.check_left_collision(CHARACTER_REC))
			break;

		else
			--character::x;

}