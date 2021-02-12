#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>



#define PRINTLN(txt) std::cout << txt << std::endl;



void update_view(vec2f& ent_view);

int main() {
	window win = window("RPG", 720, 480);

	vec2f bob = vec2f(0, 0);
	vec2f bob_view = vec2f(bob.x + 1, bob.y + 1);

	bool running = true;
	int i = 0;

	SDL_Event evn;

	while (running) {

		update_view(bob_view);

		vec2f bob_view_dir = vec2f((bob_view - bob));

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;


		PRINTLN("------------------")

		if (bob_view_dir.y > 0)
			PRINTLN("bob is looking down")

		else if (bob_view_dir.y == 0)
			PRINTLN("bob is looking middle")

		else
			PRINTLN("bob is looking up")



		if (bob_view_dir.x > 0)
			PRINTLN("bob is looking right")

		else if (bob_view_dir.x == 0)
			PRINTLN("bob is looking middle")

		else
			PRINTLN("bob is looking left")

		win.clear(i, i, i);
		win.update();

		if (i < 255)
			i++;

		else
			i = 0;

	}
	return 0;
}

void update_view(vec2f& ent_view) {
	const Uint8* key = SDL_GetKeyboardState(nullptr);

	if (key[SDL_SCANCODE_UP])
		ent_view.y -= 0.1f;

	if (key[SDL_SCANCODE_DOWN])
		ent_view.y += 0.1f;

	if (key[SDL_SCANCODE_RIGHT])
		ent_view.x += 0.1f;

	if (key[SDL_SCANCODE_LEFT])
		ent_view.x -= 0.1f;

}