#include <game.hpp>



extern void move_up(character* obj, const float delta_time);
extern void move_down(character* obj, const float delta_time);
extern void move_right(character* obj, const float delta_time);
extern void move_left(character* obj, const float delta_time);



float get_current_time() {
	return SDL_GetTicks() * 0.001f;
}

void update_datas() {
	const Uint8* key = SDL_GetKeyboardState(nullptr);

	if (key[SDL_SCANCODE_UP]) {
		character::action = MOVE;
		character::y_dir = UP;

	}

	else if (key[SDL_SCANCODE_DOWN]) {
		character::action = MOVE;
		character::y_dir = DOWN;

	} else
		action = IDLE;

	if (key[SDL_SCANCODE_RIGHT]) {
		character::action = MOVE;
		character::x_dir = RIGHT;

	}

	else if (key[SDL_SCANCODE_LEFT]) {
		character::action = MOVE;
		character::x_dir = LEFT;

	} else
		character::action = IDLE;

}

sprite* def_sprite_by_dir(sprite& u, sprite& d, sprite& r, sprite& l) {
	if (character::y_dir == UP)
		return &u;

	else if (character::y_dir == DOWN)
		return &d;

	else if (character::x_dir == RIGHT)
		return &r;

	return &l;
};

void update_pos(vec2f& ent, image& ent_tex, const float speed, const float delta_time) {
	if (character::action == MOVE) {
		if (character::y_dir == UP)
			ent.y -= speed * delta_time;

		else if (character::y_dir == DOWN)
			ent.y += speed * delta_time;

		if (character::x_dir == RIGHT)
			ent.x += speed * delta_time;

		else if (character::x_dir == LEFT)
			ent.x -= speed * delta_time;

		ent_tex.change_pos(std::ceil(ent.x), std::ceil(ent.y));

	}

}