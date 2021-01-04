#include <iostream>
#include <SDL2/SDL.h>
#include <window.hpp>
#include <sprite.hpp>
#include <player_data.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;

#define IDLE 0
#define LEFT 1
#define RIGHT 2



int main(int argc, char* argv[]) {
	PRINTLN("---- AvoidGator ----")
	PRINTLN("Try to don't become into an alligator!")

	bool game_over = false;
	int x = 0, y = 0, w = 64, h = 64;
	window win = window("AvoidGator", W, H);
	player_data dir = player_data(IDLE, RIGHT);

	sprite ademir = sprite(win, "res/sprites/ademir/Ademir Jr..png", { 0, 0, 20, 20 }, { x, y, w, h }, 4, 1);

	auto update_datas = [&] () -> void {
		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_LEFT])
			dir.change_current_data(LEFT);

		else if (key[SDL_SCANCODE_RIGHT])
			dir.change_current_data(RIGHT);

		else
			dir.change_current_data(IDLE);

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

		win.clear();
		ademir.change_pos(x, y);
		ademir.draw();
		ademir.advance_x_frame();
		win.update();

	}

	SDL_Quit();
	return 0;
}