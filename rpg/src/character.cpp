#include <character.hpp>


extern std::queue<std::string> msgs;

void character::update_pos(const float delta_time, const float fric, const area_manager area_man) {
	if (fric < 0)
		return;

	if (area_man.check_up_collision(this->xy, vec2f(this->xy.x + this->wh.x, this->xy.y + this->wh.y), this->vel)) {
		msgs.push("up collision detected");

		if (this->vel.y < 0)
			this->vel.y = 0;

	}

	if (area_man.check_down_collision(this->xy, vec2f(this->xy.x + this->wh.x, this->xy.y + this->wh.y), this->vel)) {
		msgs.push("down collision detected");

		if (this->vel.y > 0)
			this->vel.y = 0;

	}

	if (area_man.check_right_collision(this->xy, vec2f(this->xy.x + this->wh.x, this->xy.y + this->wh.y), this->vel)) {
		msgs.push("right collision detected");

		if (this->vel.x > 0)
			this->vel.x = 0;

	}

	if (area_man.check_left_collision(this->xy, vec2f(this->xy.x + this->wh.x, this->xy.y + this->wh.y), this->vel)) {
		msgs.push("left collision detected");

		if (this->vel.x < 0)
			this->vel.x = 0;

	}



	if (std::ceil(this->vel.x))
		this->xy.x += this->vel.x * delta_time;

	if (std::ceil(this->vel.y))
		this->xy.y += this->vel.y * delta_time;



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