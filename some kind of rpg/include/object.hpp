#pragma once



#include <vector>
#include <image.hpp>



class object_manager {
public:
	constexpr object_manager() { }
	~object_manager() { }

	std::vector<std::pair<
		std::pair<int, int>,
		std::pair<int, int>
	>> pos;
	std::vector<image*> textures;
	std::vector<const char*> collisions;

	void add_obj(SDL_Rect rec, const char* collision);
	void add_obj(SDL_Rect rec, image& img, const char* collision);

	void del_obj(const int index);

	bool check_up_collision(SDL_Rect rec);
	bool check_down_collision(SDL_Rect rec);
	bool check_right_collision(SDL_Rect rec);
	bool check_left_collision(SDL_Rect rec);

};