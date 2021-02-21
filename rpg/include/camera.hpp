#pragma once



#include <vec2f.hpp>
#include <window.hpp>



class camera {
private:
	vec2f cam_pos, ref, start;

public:
	camera(const vec2f ref, const vec2f start = vec2f(0, 0)) :
	cam_pos(0, 0), ref(ref), start(start) { }
	~camera() { }

	vec2f get_cam_pos() const { return this->cam_pos; }

	void update_cam(const vec2f new_ref);

};