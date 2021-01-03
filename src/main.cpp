#include <iostream>
#include <SDL2/SDL.h>
#include <window.hpp>



#define W 720
#define H 480

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;



int main(int argc, char* argv[]) {
	PRINTLN("---- AvoidGator ----")
	PRINTLN("Try to don't become into an alligator!")

	bool game_over = false;
	window win = window("AvoidGator", W, H);

	SDL_Event evn;

	while (!game_over) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		win.clear();
		win.update();

	}

	SDL_Quit();
	return 0;
}