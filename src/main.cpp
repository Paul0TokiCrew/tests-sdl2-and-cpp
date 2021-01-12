#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <window.hpp>
#include <sprite.hpp>
#include <player_data.hpp>
#include <character.hpp>
#include <object.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;

#define FPS 20

#define ADD_BORDERS object::add_obj( { 0, 0, W, 0 }, "collision" ); \
	object::add_obj( { 0, 0, 0, H }, "collision" ); \
	object::add_obj( { W, 0, 0, H }, "collision" ); \
	object::add_obj( { 0, H, W, 0 }, "collision" );



extern void move_up(character* obj);
extern void move_down(character* obj);
extern void move_right(character* obj);
extern void move_left(character* obj);



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);



	bool game_over = false;
	int jump_count = 0;
	const int delay = 1000 / FPS;

	window win = window("AvoidGator", W, H);

	character ademir = character(15, 15),
		* current_character = &ademir;

	image ground = image(win, "res/textures/ground.png", { 0, 0, 16, 16 }, { 0, 0, 0, 0 } );

	sprite al = sprite(win, "res/sprites/ademir/Ademir Jr. Left.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		ar = sprite(win, "res/sprites/ademir/Ademir Jr. Right.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		awl = sprite(win, "res/sprites/ademir/Ademir Jr. Walk Left.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		awr = sprite(win, "res/sprites/ademir/Ademir Jr. Walk Right.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		ajl = sprite(win, "res/sprites/ademir/Ademir Jr. Jump Left.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 2, 1),
		ajr = sprite(win, "res/sprites/ademir/Ademir Jr. Jump Right.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 2, 1),
		afl = sprite(win, "res/sprites/ademir/Ademir Jr. Fall Left.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 3, 1),
		afr = sprite(win, "res/sprites/ademir/Ademir Jr. Fall Right.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 3, 1),
		* current_sprite = &al;

	ADD_BORDERS
	object::add_obj( { 64 * 0, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 1, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 2, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 3, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 4, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 5, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 6, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 7, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 8, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 9, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 10, H - 64, 64, 64 }, ground, "collision");
	object::add_obj( { 64 * 11, H - 64, 64, 64 }, ground, "collision");



	auto update_datas = [&] () -> void {
		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_SPACE] && character::action1 != FALL && jump_count < 10) {
			character::action1 = JUMP;
			++jump_count;

		} else if (!object::check_down_collision(CHARACTER_REC)) {
			character::action1 = FALL;

			if (jump_count)
				--jump_count;

		} else {
			character::action1 = STAND;
			jump_count = 0;

		}



		if (key[SDL_SCANCODE_LEFT]) {
			character::dir = LEFT;
			character::action2 = MOVE;

		} else if (key[SDL_SCANCODE_RIGHT]) {
			character::dir = RIGHT;
			character::action2 = MOVE;

		} else
			character::action2 = IDLE;

	};



	auto def_sprite_by_dir = [&] (sprite& l, sprite& r) -> sprite* {
		if (character::dir == LEFT)
			return &l;

		return &r;
	};

	auto update_sprites = [&] () -> void {
		current_sprite->advance_x_frame();

		if (character::action1 == FALL)
			current_sprite = def_sprite_by_dir(afl, afr);

		else if (character::action1 == JUMP)
			current_sprite = def_sprite_by_dir(ajl, ajr);

		else if (character::action2 == MOVE)
			current_sprite = def_sprite_by_dir(awl, awr);

		else
			current_sprite = def_sprite_by_dir(al, ar);
	};



	auto update_pos = [&] () -> void {
		if (character::action1 == FALL)
			move_down(current_character);

		else if (character::action1 == JUMP)
			move_up(current_character);



		if (character::action2 == MOVE)
			if (character::dir == LEFT)
				move_left(current_character);

			else
				move_right(current_character);

		current_sprite->change_pos(character::x, character::y);
	};



	auto draw = [&] () -> void {
		SDL_Rect rec;

		current_sprite->draw();

		for (int i = 0; i < object::textures.size(); ++i) {
			
			if (object::textures[i] != nullptr) {
				rec = { object::textures[i]->get_des_x(), object::textures[i]->get_des_y(), object::textures[i]->get_des_w(), object::textures[i]->get_des_h() };
				object::textures[i]->change_pos(object::pos[i].first.first, object::pos[i].first.second);
				object::textures[i]->change_size(object::pos[i].second.first - object::pos[i].first.first, object::pos[i].second.second - object::pos[i].first.second);
				object::textures[i]->draw();
				object::textures[i]->change_pos(rec.x, rec.y);
				object::textures[i]->change_size(rec.w, rec.h);

			}

		}

	};



	SDL_Event evn;

	while (!game_over) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		update_datas();
		update_sprites();
		update_pos();

		win.clear(10, 40, 230);
		draw();
		win.update();

		SDL_Delay(delay);

	}

	IMG_Quit();
	SDL_Quit();
	return 0;
}