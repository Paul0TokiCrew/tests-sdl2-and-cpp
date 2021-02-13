#include <character.hpp>



void character::update_pos(const float delta_time) {
	this->pos.x += this->vel.x * delta_time,
	this->pos.y += this->vel.y * delta_time;



	if (std::ceil(this->vel.x) < std::ceil(this->max_vel.x))
		this->vel.x += delta_time;

	else if (std::ceil(this->vel.x) > std::ceil(this->max_vel.x))
		this->vel.x -= delta_time;



	if (std::ceil(this->vel.y) < std::ceil(this->max_vel.y))
		this->vel.y += delta_time;

	else if (std::ceil(this->vel.y) > std::ceil(this->max_vel.y))
		this->vel.y -= delta_time;

}

void character::update_datas(const Uint8* key) {
	if (key[SDL_SCANCODE_UP])
		max_vel.y = -15;

	if (key[SDL_SCANCODE_DOWN])
		max_vel.y = 15;

	if (!(key[SDL_SCANCODE_UP] || key[SDL_SCANCODE_DOWN]))
		max_vel.y = 0;



	if (key[SDL_SCANCODE_RIGHT])
		max_vel.x = 15;

	if (key[SDL_SCANCODE_LEFT])
		max_vel.x = -15;

	if (!(key[SDL_SCANCODE_RIGHT] || key[SDL_SCANCODE_LEFT]))
		max_vel.x = 0;

}