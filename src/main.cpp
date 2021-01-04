#include <iostream>
#include <SDL2/SDL.h>
#include <window.hpp>
#include <sprite.hpp>
#include <player_data.hpp>
#include <character.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;

#define FPS 20

#define LEFT 0
#define RIGHT 1

#define STAND 2
#define JUMP 3
#define FALL 4

#define IDLE 5
#define MOVE 6



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);



	bool game_over = false;
	const int delay = 1000 / FPS;

	window win = window("AvoidGator", W, H);
	player_data dir = player_data(LEFT, RIGHT),
		action1 = player_data(STAND, FALL),
		action2 = player_data(IDLE, MOVE);

	sprite al = sprite(win, "res/sprites/ademir/Ademir Jr. Left.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		ar = sprite(win, "res/sprites/ademir/Ademir Jr. Right.png", { 0, 0, 20, 20 }, { character::x, character::y, character::w, character::h }, 4, 1),
		* current_sprite = &al;



	auto update_datas = [&] () -> void {
		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_LEFT]) {
			dir.change_current_data(LEFT);
			action1.change_current_data(MOVE);

		}

		else if (key[SDL_SCANCODE_RIGHT]) {
			dir.change_current_data(RIGHT);
			action2.change_current_data(MOVE);

		} else
			action2.change_current_data(IDLE);

	};



	auto update_sprites = [&] () -> void {
		current_sprite->advance_x_frame();
		if (dir.get_current_data() == LEFT)
			current_sprite = &al;

		else
			current_sprite = &ar;
	};



	auto move_left = [&] () -> void {
		for (int i = 0; i < 15; ++i)
			--character::x;

	};

	auto move_right = [&] () -> void {
		for (int i = 0; i < 15; ++i)
			++character::x;

	};

	auto update_pos = [&] () -> void {
		if (action2.equals(MOVE))
			if (dir.equals(LEFT))
				move_left();

			else
				move_right();
	
		current_sprite->change_pos(character::x, character::y);
	};

	SDL_Event evn;

	while (!game_over) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		update_datas();
		update_sprites();
		update_pos();

		win.clear();
		current_sprite->draw();
		win.update();

		SDL_Delay(delay);

	}

	SDL_Quit();
	return 0;
}