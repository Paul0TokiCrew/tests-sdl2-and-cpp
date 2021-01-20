#include <SDL2/SDL.h>
#include <character.hpp>



int character::x = 0, character::y = 140,
	character::w = 64, character::h = 64,
	character::jump_count = 0;

player_data character::dir = player_data(LEFT, RIGHT),
	character::action1 = player_data(STAND, FALL),
	character::action2 = player_data(IDLE, MOVE);



void character::update_datas(object_manager& obj_man) {
	const Uint8* key = SDL_GetKeyboardState(nullptr);

	if (key[SDL_SCANCODE_SPACE] && character::action1 != FALL && jump_count < 10) {
		character::action1 = JUMP;
		++character::jump_count;

	} else if (!obj_man.check_down_collision(CHARACTER_REC)) {
		character::action1 = FALL;

		if (jump_count)
			--character::jump_count;

	} else {
		character::action1 = STAND;
		character::jump_count = 0;

	}



	if (key[SDL_SCANCODE_LEFT]) {
		character::dir = LEFT;
		character::action2 = MOVE;

	} else if (key[SDL_SCANCODE_RIGHT]) {
		character::dir = RIGHT;
		character::action2 = MOVE;

	} else
		character::action2 = IDLE;
}

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