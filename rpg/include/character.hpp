#pragma once



#include <vec2f.hpp>
#include <SDL2/SDL.h>



class character {
private:
	vec2f pos, vel, goal_vel, max_vel;

public:
	character(vec2f pos, vec2f vel, vec2f max_vel) :
	pos(pos), vel(vel), goal_vel(vel), max_vel(max_vel) { }
	~character() { }

	vec2f get_pos() const { return this->pos; }
	vec2f get_vel() const { return this->vel; }
	vec2f get_goal_vel() const { return this->goal_vel; }
	vec2f get_max_vel() const { return this->max_vel; }

	void update_pos(const float delta_time, const float atr);
	void update_datas(const Uint8* key);

};