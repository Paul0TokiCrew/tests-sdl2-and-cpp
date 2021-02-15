#pragma once



#include <vector>
#include <utility>
#include <vec2f.hpp>



class area_manager {
private:
	std::vector<std::pair<vec2f, vec2f>> line_areas;
	std::vector<std::pair<vec2f, float>> ang_areas;

public:
	area_manager() { }
	~area_manager() { }

	void register_line(const vec2f xy1, const vec2f xy2);
	void register_rec(const vec2f xy1, const vec2f xy2);
	void register_ang(const vec2f xy, const float r, const float ang);
	void register_circle(const vec2f xy, const int r);

};