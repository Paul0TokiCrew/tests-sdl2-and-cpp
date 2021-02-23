#pragma once



#include <vec2f.hpp>
#include <window.hpp>



class camera {
private:
	vec2f cam_pos, & ref;
	float x_diff, y_diff;

	void update_x_diff();
	void update_y_diff();

public:
	camera(vec2f& ref) :
	cam_pos(0, 0), ref(ref), x_diff(this->ref.x - this->cam_pos.x), y_diff(this->ref.y - this->cam_pos.y) { }
	~camera() { }

	vec2f get_cam_pos() const { return this->cam_pos; }

	void update_cam();

};