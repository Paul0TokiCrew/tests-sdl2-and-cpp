#pragma once



#include <vector>
#include <utility>
#include <tuple>
#include <vec2f.hpp>



class area_manager {
private:
	std::vector<std::pair<vec2f, vec2f>> line_areas;
	std::vector<std::tuple<vec2f, float, float>> ang_areas;

public:
	area_manager() { }
	~area_manager() { }

	void register_line(const vec2f xy1, const vec2f xy2);
	void register_rec(const vec2f xy1, const vec2f xy2);
	void register_ang(const vec2f xy, const float r, const float a);
	void register_circle(const vec2f xy, const int r);

	bool check_collision(const vec2f other_xy, const vec2f other_wh) const;

};