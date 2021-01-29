#include <vec2f.hpp>



void vec2f::move(float x_speed, float y_speed) {
	this->x += x_speed;
	this->y += y_speed;
}

float vec2f::get_length() const {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
}

float vec2f::get_length_sqr() const {
	return std::pow(this->x, 2) + std::pow(this->y, 2);
}

vec2f vec2f::normalize() const {
	vec2f vec = vec2f(this->x / this->get_length(), this->y / this->get_length());
	return vec;
}

vec2f vec2f::operator+(const vec2f other) {
	vec2f vec = vec2f(this->x + other.x, this->y + other.y);
	return vec;
}

vec2f vec2f::operator-(const vec2f other) {
	vec2f vec = vec2f(this->x - other.x, this->y - other.y);
	return vec;
}

vec2f vec2f::operator*(const vec2f other) {
	vec2f vec = vec2f(this->x * other.x, this->y * other.y);
	return vec;
}

vec2f vec2f::operator/(const vec2f other) {
	vec2f vec = vec2f(this->x / other.x, this->y / other.y);
	return vec;
}



std::ostream& operator<<(std::ostream& os, const vec2f vec) {
	os << "{ " << vec.x << ", " << vec.y << " }";
	return os;
}

std::wostream& operator<<(std::wostream& wos, const vec2f vec) {
	wos << "{ " << vec.x << ", " << vec.y << " }";
	return wos;
}