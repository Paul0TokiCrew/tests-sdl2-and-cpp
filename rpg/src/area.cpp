#include <area.hpp>



void area_manager::register_area(const vec2f xy1, const vec2f xy2) {
	this->areas.push_back(std::make_pair(xy1, xy2));
}

bool area_manager::check_collision(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= i.second.x &&
			other_xy2.x >= i.first.x &&
			other_xy1.y <= i.second.y &&
			other_xy2.y >= i.first.y
		)
			return true;

	}

	return false;
}

bool area_manager::check_up_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= i.second.x &&
			other_xy2.x >= i.first.x &&
			other_xy1.y <= i.second.y &&
			other_xy2.y > i.second.y
//			other_vel.y < 0
		)
			return true;

	}

	return false;
}

bool area_manager::check_down_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= i.second.x &&
			other_xy2.x >= i.first.x &&
			other_xy1.y < i.first.y &&
			other_xy2.y >= i.first.y
//			other_vel.y > 0
		)
			return true;

	}

	return false;
}

bool area_manager::check_right_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x < i.first.x &&
			other_xy2.x >= i.first.x &&
			other_xy1.y <= i.second.y &&
			other_xy2.y >= i.first.y
//			other_vel.x > 0
		)
			return true;

	}

	return false;
}

bool area_manager::check_left_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= i.second.x &&
			other_xy2.x > i.second.x &&
			other_xy1.y <= i.second.y &&
			other_xy2.y >= i.first.y
//			other_vel.x < 0
		)
			return true;

	}

	return false;
}
