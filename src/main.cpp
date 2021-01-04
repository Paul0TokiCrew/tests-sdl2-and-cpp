#include <iostream>
#include <SDL2/SDL.h>
#include <window.hpp>
#include <sprite.hpp>
#include <player_data.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;

#define FPS 20

#define IDLE 0
#define LEFT 1
#define RIGHT 2



int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);



	bool game_over = false;
	int x = 0, y = 0, w = 64, h = 64;
	const int delay = 1000 / FPS;

	window win = window("AvoidGator", W, H);
	player_data dir = player_data(IDLE, RIGHT);

	sprite al = sprite(win, "res/sprites/ademir/Ademir Jr. Left.png", { 0, 0, 20, 20 }, { x, y, w, h }, 4, 1),
		ar = sprite(win, "res/sprites/ademir/Ademir Jr. Right.png", { 0, 0, 20, 20 }, { x, y, w, h }, 4, 1),
		* current_sprite = &al;


	auto update_datas = [&] () -> void {
		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_LEFT])
			dir.change_current_data(LEFT);

		else if (key[SDL_SCANCODE_RIGHT])
			dir.change_current_data(RIGHT);

		else
			dir.change_current_data(IDLE);

	};

	auto update_sprites = [&] () -> void {
		current_sprite->advance_x_frame();
		if (dir.get_current_data() == LEFT)
			current_sprite = &al;

		else
			current_sprite = &ar;
	};

	auto update_pos = [&] () -> void {
		if (dir.get_current_data() == LEFT)
			x -= 5;

		else if (dir.get_current_data() == RIGHT)
			x += 5;

	};

	SDL_Event evn;

	while (!game_over) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		update_datas();
		update_pos();
		update_sprites();

		win.clear();
		current_sprite->change_pos(x, y);
		current_sprite->draw();
		win.update();

		SDL_Delay(delay);

	}

	SDL_Quit();
	return 0;
}