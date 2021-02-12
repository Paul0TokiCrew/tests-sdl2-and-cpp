#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>



#define PRINTLN(txt) std::cout << txt << std::endl;



int main() {
	window win = window("RPG", 720, 480);

	vec2f bob = vec2f(0, 0);
	vec2f bob_view = vec2f(bob.x + 1, bob.y + 1);

	bool running = true;

	int i = 0;

	SDL_Event evn;

	PRINTLN((bob - bob_view).normalize());

	while (running) {

		vec2f bob_view_dir = vec2f((bob_view - bob));

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		PRINTLN("------------------")

		if (bob_view_dir.y > 0)
			PRINTLN("bob is looking at down")

		else
			PRINTLN("bob is looking at up")

		if (bob_view_dir.x > 0)
			PRINTLN("bob is looking at right")

		else
			PRINTLN("bob is looking at left")

		win.clear(i, i, i);
		win.update();

		if (i < 255)
			i++;

		else
			i = 0;

	}
	return 0;
}