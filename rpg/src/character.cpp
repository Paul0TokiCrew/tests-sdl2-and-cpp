#include <character.cpp>



void update_pos(const float delta_time) {
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



	this->sprite.change_pos(std::ceil(this->pos.x), std::ceil(this->pos.y));

}