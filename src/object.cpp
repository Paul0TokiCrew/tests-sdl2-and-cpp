#include <cstddef>
#include <vector>
#include <SDL2/SDL.h>
#include <object.hpp>



int object_manager::add_obj(SDL_Rect rec, const char* collision_dir) {
	this->pos.push_back( {
		{ rec.x, rec.y },
		{ rec.x + rec.w, rec.y + rec.h }
	} );

	this->collisions.push_back(collision_dir);
	return this->obj_counter++;
}

void object_manager::del_obj(const int index) {
	if (index >= this->obj_counter)
		return;

	this->pos.erase(this->pos.begin() + index);
	this->collisions.erase(this->collisions.begin() + index);
}

bool object_manager::check_up_collision(SDL_Rect rec) const {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'u') != nullptr &&
			rec.y == i->second.second &&
			(rec.x < i->second.first && rec.x + rec.w > i->first.first) )
			return true;

	return false;
}

bool object_manager::check_down_collision(SDL_Rect rec) const {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'd') != nullptr &&
			rec.y + rec.h == i->first.second &&
			(rec.x < i->second.first && rec.x + rec.w > i->first.first) )
			return true;

	return false;
}

bool object_manager::check_right_collision(SDL_Rect rec) const {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'r') != nullptr &&
			rec.x + rec.w == i->first.first &&
			(rec.y < i->second.second && rec.y + rec.w > i->first.second) )
			return true;

	return false;
}

bool object_manager::check_left_collision(SDL_Rect rec) const {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'l') != nullptr &&
			rec.x == i->second.first &&
			(rec.y < i->second.second && rec.y + rec.w > i->first.second) )
			return true;

	return false;
}