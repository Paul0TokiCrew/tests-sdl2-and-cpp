#pragma once



#include <vec2f.hpp>
#include <window.hpp>



class camera {
private:
	const window& win;
	vec2f ref_xy1, ref_xy2,
		lim_xy1, lim_xy2,
		start_xy1, start_xy2;

public:
	camera(const window& win, const vec2f ref_xy1, const vec2f ref_xy2, const vec2f lim_xy1, const vec2f lim_xy2, const vec2f start_xy1 = vec2f(0, 0), const vec2f start_xy2 = vec2f(0, 0)) :
	win(win), ref_xy1(ref_xy1), ref_xy2(ref_xy2), lim_xy1(lim_xy1), lim_xy2(lim_xy2), start_xy1(start_xy1), start_xy2(start_xy2) { }
	~camera() { }

};