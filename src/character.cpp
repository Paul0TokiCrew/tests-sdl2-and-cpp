#include <character.hpp>



int character::x = 0, character::y = 140,
	character::w = 64, character::h = 64;

player_data character::dir = player_data(LEFT, RIGHT),
	character::action1 = player_data(STAND, FALL),
	character::action2 = player_data(IDLE, MOVE);



void move_up(character* obj) {

	for (int i = 0; i < obj->y_speed; ++i)
		if (obj->lvl.check_up_collision(CHARACTER_REC))
			break;

		else
			--character::y;

}

void move_down(character* obj) {

	for (int i = 0; i < obj->y_speed; ++i)
		if (obj->lvl.check_down_collision(CHARACTER_REC))
			break;

		else
			++character::y;

}

void move_right(character* obj) {

	for (int i = 0; i < obj->x_speed; ++i)
		if (obj->lvl.check_right_collision(CHARACTER_REC))
			break;

		else
			++character::x;

}

void move_left(character* obj) {

	for (int i = 0; i < obj->x_speed; ++i)
		if (obj->lvl.check_left_collision(CHARACTER_REC))
			break;

		else
			--character::x;

}