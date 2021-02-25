#include <iostream>
#include <queue>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vec2f.hpp>
#include <window.hpp>
#include <image.hpp>
#include <area.hpp>
#include <camera.hpp>
#include <character.hpp>



#define W 720
#define H 480
#define PRINTLN(txt) std::cout << txt << std::endl;



std::queue<std::string> msgs;

float get_current_time();

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	const window win = window("RPG", W, H);

	character chad = character(vec2f(0, 0), vec2f(120, 120), vec2f(0, 0), vec2f(100, 100));
	image chad_img = image(win, "res/chad.png", { 0, 0, 600, 600 }, { 0, 0, 120, 120 });
	image gru_no = image(win, "res/no.jpg", { 0, 0, 1280, 720 }, { 300, 300, 50, 50 });
	image gru_no2 = image(win, "res/no.jpg", { 0, 0, 1280, 720 }, { 500, 100, 100, 300 });

	camera chad_cam = camera(chad.get_xy());
	vec2f prev_cam_pos = chad_cam.get_cam_pos();

	area_manager area_man = area_manager();
	area_man.register_area(vec2f(300, 300), vec2f(350, 350), &gru_no);
	area_man.register_area(vec2f(500, 100), vec2f(600, 400), &gru_no2);

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
		chad.update_pos(delta_time, 500, area_man);
		chad_img.change_pos(std::ceil(chad.get_xy().x), std::ceil(chad.get_xy().y));
		chad_cam.update_cam(chad.get_xy());
		area_man.change_areas_pos(chad_cam.get_cam_pos());

		PRINTLN("---------------------------")
		PRINTLN("-- INFO")
		PRINTLN("chad xy1: " << chad.get_xy())
		PRINTLN("chad xy2: " << vec2f(chad.get_xy() + chad.get_wh()))
		PRINTLN("chad wh: " << chad.get_wh())
		PRINTLN("chad vel: " << chad.get_vel())
		PRINTLN("chad cam pos: " << chad_cam.get_cam_pos())
		PRINTLN("time: " << get_current_time())
		PRINTLN("delta time: " << delta_time)
		PRINTLN("-- MESSAGES")

		while (!msgs.empty()) {

			PRINTLN(msgs.front())
			msgs.pop();

		}

		win.clear(i, i, i);
		chad_img.draw();
		area_man.draw_areas();
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
