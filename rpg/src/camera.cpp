#include <camera.hpp>



void camera::update_cam(const vec2f& new_xy1, const vec2f& new_xy2) {
	vec2f change_xy1 = vec2f(new_xy1 - this->ref_xy1);
	vec2f change_xy2 = vec2f(new_xy2 - this->ref_xy2);

	if (
		change_xy1 > this->start_xy1 ||
		change_xy2 > this->start_xy2 ||
		change_xy1 < this->start_xy1 ||
		change_xy2 < this->start_xy2
	) {
		this->cam_pos = this->cam_pos + (new_xy1 - this->ref_xy1);

		if (this->cam_pos.x < this->lim_xy1.x)
			this->cam_pos.x = this->lim_xy1.x;

		if (this->cam_pos.y < this->lim_xy1.y)
			this->cam_pos.y = this->lim_xy1.y;

		if (this->cam_pos.x + this->win.get_w() > this->lim_xy2.x)
			this->cam_pos.x = this->lim_xy2.x - this->win.get_w();

		if (this->cam_pos.y + this->win.get_h() > this->lim_xy2.y)
			this->cam_pos.y = this->lim_xy2.y - this->win.get_h(); 

	}

}