#include <area.hpp>



void area_manager::register_area(const vec2f xy, const vec2f wh) {
	this->areas.push_back(std::make_pair(xy, wh));
}