#include <iostream>
#include <SDL2/SDL.h>
#include <window.hpp>
#include <sprite.hpp>
#include <player_data.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;

#define LEFT 0
#define RIGHT 1



int main(int argc, char* argv[]) {
	PRINTLN("---- AvoidGator ----")
	PRINTLN("Try to don't become into an alligator!")

	bool game_over = false;
	window win = window("AvoidGator", W, H);
	player_data dir = player_data(LEFT, RIGHT);

	sprite ademir = sprite(win, "res/sprites/ademir/Ademir Jr..png", { 0, 0, 20, 20 }, { 0, 0, 64, 64 }, 4, 1);

	auto update_datas = [&] () -> void {
		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (key[SDL_SCANCODE_LEFT])
			dir.change_current_data(LEFT);

		else if (key[SDL_SCANCODE_RIGHT])
			dir.change_current_data(RIGHT);

	};

	SDL_Event evn;

	while (!game_over) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		update_datas();
		PRINTLN(dir.get_current_data())

		win.clear();
		ademir.draw();
		ademir.advance_x_frame();
		win.update();

	}

	SDL_Quit();
	return 0;
}