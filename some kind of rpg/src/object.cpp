#include <object.hpp>



void object_manager::add_obj(SDL_Rect rec, const char* collision) {
	this->pos.push_back( {
		{ rec.x, rec.y },
		{ rec.x + rec.w, rec.y + rec.h }
	} );

	this->textures.push_back(nullptr);
	this->collisions.push_back(collision);
}

void object_manager::add_obj(SDL_Rect rec, image& img, const char* collision) {
	this->pos.push_back( {
		{ rec.x, rec.y },
		{ rec.x + rec.w, rec.y + rec.h }
	} );

	this->textures.push_back(&img);
	this->collisions.push_back(collision);
}

void object_manager::del_obj(const int index) {
	this->pos.erase(this->pos.begin() + index);
	this->textures.erase(this->textures.begin() + index);
	this->collisions.erase(this->collisions.begin() + index);
}

bool object_manager::check_up_collision(SDL_Rect rec) {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'u') != nullptr &&
			rec.y == i->second.second &&
			(rec.x < i->second.first && rec.x + rec.w > i->first.first) )
			return true;

	return false;
}

bool object_manager::check_down_collision(SDL_Rect rec) {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'd') != nullptr &&
			rec.y + rec.h == i->first.second &&
			(rec.x < i->second.first && rec.x + rec.w > i->first.first) )
			return true;

	return false;
}

bool object_manager::check_right_collision(SDL_Rect rec) {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'r') != nullptr &&
			rec.x + rec.w == i->first.first &&
			(rec.y < i->second.second && rec.y + rec.w > i->first.second) )
			return true;

	return false;
}

bool object_manager::check_left_collision(SDL_Rect rec) {
	auto i = this->pos.begin();
	auto j = this->collisions.begin();

	for (; i != this->pos.end() && j != this->collisions.end(); ++i, ++j)
		if (strchr(*j, 'l') != nullptr &&
			rec.x == i->second.first &&
			(rec.y < i->second.second && rec.y + rec.w > i->first.second) )
			return true;

	return false;
}