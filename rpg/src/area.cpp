#include <area.hpp>



void area_manager::register_area(const vec2f xy1, const vec2f xy2, image* tex) {
	this->areas.push_back(std::make_tuple(xy1, xy2, tex));
}

bool area_manager::check_trigger(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= std::get<0>(i).x &&
			other_xy2.x >= std::get<0>(i).x &&
			other_xy1.y <= std::get<1>(i).y &&
			other_xy2.y >= std::get<0>(i).y
		)
			return true;

	}

	return false;
}

bool area_manager::check_up_collision(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= std::get<1>(i).x &&
			other_xy2.x >= std::get<0>(i).x &&
			other_xy1.y <= std::get<1>(i).y &&
			other_xy2.y > std::get<1>(i).y &&
			other_xy1.y > std::get<0>(i).y
		)
			return true;

	}

	return false;
}

bool area_manager::check_down_collision(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= std::get<1>(i).x &&
			other_xy2.x >= std::get<0>(i).x &&
			other_xy1.y < std::get<0>(i).y &&
			other_xy2.y >= std::get<0>(i).y &&
			other_xy2.y < std::get<1>(i).y 
		)
			return true;

	}

	return false;
}

bool area_manager::check_right_collision(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x < std::get<0>(i).x &&
			other_xy2.x >= std::get<0>(i).x &&
			other_xy1.y <= std::get<1>(i).y &&
			other_xy2.y >= std::get<0>(i).y &&
			other_xy2.x < std::get<1>(i).x
		)
			return true;

	}

	return false;
}

bool area_manager::check_left_collision(const vec2f other_xy1, const vec2f other_xy2) const {

	for (auto i : this->areas) {

		if (
			other_xy1.x <= std::get<1>(i).x &&
			other_xy2.x > std::get<1>(i).x &&
			other_xy1.y <= std::get<1>(i).y &&
			other_xy2.y >= std::get<0>(i).y &&
			other_xy1.x > std::get<0>(i).x
		)
			return true;

	}

	return false;
}

void area_manager::change_areas_pos(const vec2f mod) {

	for (auto i : this->areas) {
		
		image*& img = std::get<2>(i);
		img->change_pos(img->get_old_des().x - std::ceil(mod.x), img->get_old_des().y - std::ceil(mod.y));

	}

}

void area_manager::draw_areas() const {

	for (auto i : this->areas) {

		if (std::get<2>(i) != nullptr) {
			SDL_Rect rec = std::get<2>(i)->get_des();

			std::get<2>(i)->change_size(std::get<1>(i).x - std::get<0>(i).x, std::get<1>(i).y -  std::get<0>(i).y);

			std::get<2>(i)->draw();

			std::get<2>(i)->change_size(rec.w, rec.h);

		}

	}

}
