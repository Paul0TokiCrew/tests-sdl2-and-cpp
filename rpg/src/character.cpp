#include <character.hpp>



void character::update_pos(const float delta_time, const float fric) {
	if (fric < 0)
		return;

	if (std::ceil(this->vel.x))
		this->pos.x += this->vel.x * delta_time;

	if (std::ceil(this->vel.y))
		this->pos.y += this->vel.y * delta_time;



	if (std::ceil(this->vel.x) < std::ceil(this->goal_vel.x))
		this->vel.x += delta_time * fric;

	else if (std::ceil(this->vel.x) > std::ceil(this->goal_vel.x))
		this->vel.x -= delta_time * fric;



	if (std::ceil(this->vel.y) < std::ceil(this->goal_vel.y))
		this->vel.y += delta_time * fric;

	else if (std::ceil(this->vel.y) > std::ceil(this->goal_vel.y))
		this->vel.y -= delta_time * fric;

}

void character::update_datas(const Uint8* key) {
	if (key[SDL_SCANCODE_UP])
		goal_vel.y = -(max_vel.y);

	if (key[SDL_SCANCODE_DOWN])
		goal_vel.y = max_vel.y;

	if (!(key[SDL_SCANCODE_UP] || key[SDL_SCANCODE_DOWN]))
		goal_vel.y = 0;



	if (key[SDL_SCANCODE_RIGHT])
		goal_vel.x = max_vel.x;

	if (key[SDL_SCANCODE_LEFT])
		goal_vel.x = -(max_vel.x);

	if (!(key[SDL_SCANCODE_RIGHT] || key[SDL_SCANCODE_LEFT]))
		goal_vel.x = 0;

}