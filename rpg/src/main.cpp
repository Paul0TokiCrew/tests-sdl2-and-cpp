#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>
#include <character.hpp>



#define PRINTLN(txt) std::cout << txt << std::endl;



float get_current_time();

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window win = window("RPG", 720, 480);

	character chad = character(vec2f(0, 0), vec2f(0, 0), vec2f(100, 100));
	image chad_img = image(win, "res/chad.png", { 0, 0, 600, 600 }, { 0, 0, 120, 120 });

	bool running = true;
	int i = 0;

	float current_time = get_current_time();

	SDL_Event evn;

	while (running) {

		float new_time = get_current_time();
		float delta_time =  new_time - current_time;
		current_time = new_time;

		const Uint8* key = SDL_GetKeyboardState(nullptr);

		if (delta_time > 0.20f)
			delta_time = 0.20f;



		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;

		chad.update_datas(key);
		chad.update_pos(delta_time, 500);
		chad_img.change_pos(std::ceil(chad.get_pos().x), std::ceil(chad.get_pos().y));

		PRINTLN("---------------------------")
		PRINTLN("chad pos: " << chad.get_pos())
		PRINTLN("chad vel: " << chad.get_vel())
		PRINTLN("time: " << get_current_time())
		PRINTLN("delta time: " << delta_time)

		win.clear(i, i, i);
		chad_img.draw();
		win.update();

		if (i < 255)
			i++;

		else
			i = 0;

	}

	IMG_Quit();
	SDL_Quit();
	return 0;
}

float get_current_time() {
	return SDL_GetTicks() / 1000.0f;
}