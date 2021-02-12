#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>



#define PRINTLN(txt) std::cout << txt << std::endl;



void update_pos(vec2f& ent, image& ent_img, vec2f& ent_vel, const vec2f max_vel, const float delta_time);
float get_current_time();

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window win = window("RPG", 720, 480);

	vec2f chad = vec2f(0, 0);
	vec2f chad_vel = vec2f(1, 1);
	vec2f chad_max_vel = vec2f(10, 10);
	image chad_img = image(win, "res/chad.png", { 0, 0, 600, 600 }, { 0, 0, 120, 120 });

	bool running = true;
	int i = 0;

	SDL_Event evn;

	while (running) {

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;


		update_pos(chad, chad_img, chad_vel, chad_max_vel, 0.01f);

		PRINTLN("---------------------------")
		PRINTLN("chad pos: " << chad)
		PRINTLN("chad vel: " << chad_vel)
		PRINTLN("time: " << get_current_time())

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

void update_pos(vec2f& ent, image& ent_img, vec2f& ent_vel, const vec2f max_vel, const float delta_time) {
	ent.x += ent_vel.x * delta_time,
	ent.y += ent_vel.y * delta_time;



	if (std::ceil(ent_vel.x) < std::ceil(max_vel.x))
		ent_vel.x += delta_time;

	else if (std::ceil(ent_vel.x) > std::ceil(max_vel.x))
		ent_vel.x -= delta_time;



	if (std::ceil(ent_vel.y) < std::ceil(max_vel.y))
		ent_vel.y += delta_time;

	else if (std::ceil(ent_vel.y) > std::ceil(max_vel.y))
		ent_vel.y -= delta_time;



	ent_img.change_pos(std::ceil(ent.x), std::ceil(ent.y));

}

float get_current_time() {
	return SDL_GetTicks() / 1000.0f;
}