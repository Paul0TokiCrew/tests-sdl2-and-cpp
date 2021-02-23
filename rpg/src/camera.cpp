#include <camera.hpp>



void camera::update_x_diff() {
	this->x_diff = this->cam_pos.x - this->ref.x;
}

void camera::update_y_diff() {
	this->y_diff = this->cam_pos.y - this->ref.y;
}

void camera::update_cam() {
	float prev_x_diff = this->x_diff, prev_y_diff = this->y_diff;
	
	this->update_x_diff();
	this->update_y_diff();

	if (prev_x_diff < this->x_diff || prev_x_diff > this->x_diff)
		this->cam_pos.x += this->x_diff - prev_x_diff;

	if (prev_y_diff > this->y_diff || prev_y_diff < this->y_diff)
		this->cam_pos.y += this->y_diff - prev_y_diff;

}