#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>

int main() {
	window win = window("RPG", 720, 480);
	bool running = true;

	int i = 0;

	SDL_Event evn;

	while (running) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		win.clear(i, i, i);
		win.update();

		if (i < 255)
			i++;

		else
			i = 0;

	}
	return 0;
}