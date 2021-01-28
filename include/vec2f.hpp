#pragma once



#include <ostream>
#include <cmath>



class vec2f {
public:
	vec2f() { }
	constexpr vec2f(const float x, const float y) :
	x(x), y(y) { }
	constexpr vec2f(const entity& ent) :
	x(ent.x), y(ent.y) { }
	~vec2f() { }

	float x, y;

	void move(const float x_speed, const float y_speed);

	float get_length();
	float get_length_sqr();

	friend std::ostream& operator<<(std::ostream& os, const entity& ent);
	friend std::wostream& operator<<(std::wostream& wos, const entity& ent);

};