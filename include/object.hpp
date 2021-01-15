#pragma once



#include <vector>
#include <cstddef>
#include <SDL2/SDL.h>



class object_manager {
private:
	int obj_counter;

	std::vector<std::pair<
		std::pair<int, int>,
		std::pair<int, int>
	>> pos;
	std::vector<const char*> collisions;

public:
	object_manager() :
	obj_counter(0) { }
	~object_manager() { }

	int add_obj(SDL_Rect rec, const char* collision_dir);
	void del_obj(const int index);

	bool check_up_collision(SDL_Rect rec) const;
	bool check_down_collision(SDL_Rect rec) const;
	bool check_right_collision(SDL_Rect rec) const;
	bool check_left_collision(SDL_Rect rec) const;

};