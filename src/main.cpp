#include <game.hpp>

BEGIN(eae)

	SDL_Event evn;

	float current_time = get_current_time();

	while(!game_over) {

		float new_time = get_current_time();
		float delta_time = new_time - current_time;
		current_time = new_time;

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				game_over = true;

		PRINTLN("--------------------------")
		PRINTLN("current time: " << current_time)
		PRINTLN("delta time: " << delta_time)

	}

END