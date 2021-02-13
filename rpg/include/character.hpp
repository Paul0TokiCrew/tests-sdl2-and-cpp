#pragma once



#include <vec2f.hpp>



class character {
private:
	vec2f pos, vel, max_vel;

public:
	character(vec2f pos, vec2f vel, vec2f max_vel) :
	pos(pos), vel(vel), max_vel(max_vel) { }
	~character() { }

	void update_pos(const float delta_time);

};