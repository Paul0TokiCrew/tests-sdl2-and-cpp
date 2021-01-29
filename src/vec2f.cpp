#include <vec2f.hpp>



void vec2f::move(float x_speed, float y_speed) {
	this->x += x_speed;
	this->y += y_speed;
}

float get_length() {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
}

float get_length_sqr() {
	return std::pow(this->x, 2) + std::pow(this->y, 2);
}

vec2f operator+(const vec2f other) {
	vec2f vec = vec2f(this->x + other.x, this->y + other.y);
	return vec;
}

vec2f operator-(const vec2f other) {
	vec2f ent = vec2f(this->x - other.x, this->y - other.y);
	return ent;
}

vec2f operator*(const vec2f other) {
	vec2f ent = vec2f(this->x * other.x, this->y * other.y);
	return ent;
}

vec2f operator/(const vec2f other) {
	vec2f ent = vec2f(this->x / other.x, this->y / other.y);
	return ent;
}

std::ostream& operator<<(std::ostream& os, const vec2f ent) {
	os << "{ " << ent.x << ", " << ent.y << " }";
	return os;
}

std::wostream& operator<<(std::wostream& wos, const vec2f ent) {
	os << "{ " << ent.x << ", " << ent.y << " }";
	return wos;
}