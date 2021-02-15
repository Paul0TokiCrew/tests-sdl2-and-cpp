#include <area.hpp>



void register_line(const vec2f xy1, const vec2f xy2) {
	this->line_areas.push_back(std::make_pair(xy1, xy2));
}

void register_rec(const vec2f xy1, const vec2f xy2) {
	vec2f up1 = vec2f(xy1), up2 = vec2f(xy2.x, xy1.y),
	down1 = vec2f(xy1.x, xy2.y), down2 = vec2f(xy2),
	right1 = vec2f(xy1), right2 = vec2f(xy1.x, xy2.y),
	left1 = vec2f(xy2.x xy1.y), left2 = vec2f(xy2);

	this->line_areas.push_back(std::make_pair(up1, up2));
	this->line_areas.push_back(std::make_pair(down1, down2));
	this->line_areas.push_back(std::make_pair(right1, right2));
	this->line_areas.push_back(std::make_pair(left1, left2));

}