#pragma once



#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <window.hpp>
#include <vec2f.hpp>
#include <sprite.hpp>
#include <player_data.hpp>
#include <character.hpp>
#include <object.hpp>



#define W 720
#define H 480

#define FPS 20

#define BEGIN(win_name) int main(int argc, char* argv[]) {	\
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);				\
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);					\
															\
	bool game_over = false;									\
															\
	window win = window(#win_name, W, H);

#define END IMG_Quit();	\
	SDL_Quit();			\
	return 0;			\
}

#define PRINT(txt) std::cout << txt;
#define PRINTLN(txt) std::cout << txt << std::endl;



float get_current_time();

void update_datas();

sprite* def_sprite_by_dir(sprite& u, sprite& d, sprite& r, sprite& l);
