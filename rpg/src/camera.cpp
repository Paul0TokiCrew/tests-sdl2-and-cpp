#include <camera.hpp>



void camera::update_cam(const vec2f new_ref) {
	const vec2f ref_diff = vec2f(new_ref - ref);

	if (
		ref_diff.x > this->start.x ||
		ref_diff.x < -(this->start.x)
	)
		this->cam_pos.x = ref_diff.x;

	if (
		ref_diff.y > this->start.y ||
		ref_diff.y < -(this->start.y)
	)
		this->cam_pos.y = ref_diff.y;

}