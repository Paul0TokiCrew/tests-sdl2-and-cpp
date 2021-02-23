#include <camera.hpp>



void camera::update_x_diff() {
	this->x_diff = this->cam_pos.x - this->ref.x;
}

void camera::update_y_diff() {
	this->y_diff = this->cam_pos.y - this->ref.y;
}

void camera::update_cam(const vec2f new_ref) {
	
}