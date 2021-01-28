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

std::ostream& operator<<(std::ostream& os, const entity& ent) {
	os << "{ " << ent.x << ", " << ent.y << " }";
	return os;
}

std::wostream& operator<<(std::wostream& wos, const entity& ent) {
	os << "{ " << ent.x << ", " << ent.y << " }";
	return wos;
}