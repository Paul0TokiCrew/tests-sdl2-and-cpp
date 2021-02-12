#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>



#define PRINTLN(txt) std::cout << txt << std::endl;



void update_pos(vec2f& ent, vec2f& ent_vel, const float delta_time, const vec2f max_vel);

int main() {
	window win = window("RPG", 720, 480);

	vec2f bob = vec2f(0, 0);
	vec2f bob_vel = vec2f(1, 1);

	bool running = true;
	int i = 0;

	SDL_Event evn;

	while (running) {

		vec2f bob_distance = vec2f(bob - vec2f(0, 0));

		while (SDL_PollEvent(&evn))
			if (evn.type == SDL_QUIT)
				running = false;


		update_pos(bob, bob_vel, 0.01f, vec2f(3, 3));

		PRINTLN("bob pos: " << bob)
		PRINTLN("bob vel: " << bob_vel)
		PRINTLN("---------------------------")

		win.clear(i, i, i);
		win.update();

		if (i < 255)
			i++;

		else
			i = 0;

	}
	return 0;
}

void update_pos(vec2f& ent, vec2f& ent_vel, const float delta_time, const vec2f max_vel) {
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

}