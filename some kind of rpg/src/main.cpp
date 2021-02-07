#include <game.hpp>

BEGIN(eae)

	bool debug = false;

	if (!strcmp(argv[1], "debug"))
		debug = true;

	vec2f bob = vec2f(8, 6);
	vec2f bob_origin = vec2f(bob);

	SDL_Event evn;

	float current_time = get_current_time();

	while(!game_over) {

		float new_time = get_current_time();
		float delta_time = new_time - current_time;
		current_time = new_time;

		if (delta_time > 0.1f)
			delta_time = 0.1f;

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;


		bob.move(0.1f, 0.1f);

		win.clear(0, 0, 255);
		win.update();

		if (debug) {
			PRINTLN("--------------------------")

			PRINTLN("----- time info:")
			PRINTLN("current time: " << current_time)
			PRINTLN("delta time: " << delta_time)

			PRINTLN("----- characters pos info:")
			PRINTLN("bob pos: " << bob)
			PRINTLN("bob origin: " << bob_origin)
			PRINTLN("distance: " << vec2f(bob_origin - bob).get_length())

		}

	}

END