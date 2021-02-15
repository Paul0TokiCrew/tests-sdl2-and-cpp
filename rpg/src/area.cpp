#include <area.hpp>



void register_rec(const vec2f xy1, const vec2f xy2) {
	this->areas.push_back(std::make_pair(xy1, xy2);
}

bool check_collision(const vec2f other_xy1, const vec2f other_xy2) const {
	auto i = this->areas.begin();

	for (; i != this->areas.end(); ++i) {

		if (
			other_xy1.x <= i->second.x &&
			other_xy2.x >= i->first.x &&
			other_xy1.y >= i->second.y &&
			other_xy2.y <= i->first.y
		)
			return true;

	}

	return false;
}