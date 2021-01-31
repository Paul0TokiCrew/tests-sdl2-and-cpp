#include <game.hpp>



float get_current_time() {
	return ((float) std::clock()) / CLOCKS_PER_SEC;
}

float get_current_sdl_time() {
	return SDL_GetTicks() * 0.001f;
}

void update_datas(object_manager* obj_man) {
	const Uint8* key = SDL_GetKeyboardState(nullptr);

	if (key[SDL_SCANCODE_SPACE] && character::action1 != FALL && character::jump_count < 10) {
		character::action1 = JUMP;
		++character::jump_count;

	} else if (!obj_man->check_down_collision(CHARACTER_REC)) {
		character::action1 = FALL;

		if (character::jump_count)
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

sprite* def_sprite_by_dir(sprite& l, sprite& r) {
	if (character::dir == RIGHT)
		return &r;

	return &l;
};