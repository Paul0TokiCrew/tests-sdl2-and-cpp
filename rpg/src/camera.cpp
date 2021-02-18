#include <camera.hpp>



void camera::update_cam(const vec2f& new_xy1, const vec2f& new_xy2) {
	if (
		new_xy1 - this->ref_xy1 != this->start_xy1 ||
		new_xy2 - this->ref_xy2 != this->start_xy2
	) {
		cam_pos = new_xy1 - this->ref_xy1;

	}
}