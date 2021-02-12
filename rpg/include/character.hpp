#pragma once



#include <vec2f.hpp>
#include <image>



class character {
private:
	vec2f pos, vel, max_vel;
	image sprite;

public:
	constexpr character(vec2f pos, vec2f vel, vec2f max_vel, image sprite) :
	pos(pos), vel(vel), max_vel(max_vel), sprite(sprite) { }
	~character() { }

	void update_pos(const float delta_time);

};