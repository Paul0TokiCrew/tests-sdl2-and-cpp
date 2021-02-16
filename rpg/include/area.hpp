#pragma once



#include <vector>
#include <utility>
#include <vec2f.hpp>



class area_manager {
private:
	std::vector<std::pair<vec2f, vec2f>> areas;

public:
	area_manager() { }
	~area_manager() { }

	void register_area(const vec2f xy1, const vec2f xy2);

	bool check_collision(const vec2f other_xy1, const vec2f other_xy2) const;
	bool check_up_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const;
	bool check_down_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const;
	bool check_right_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const;
	bool check_left_collision(const vec2f other_xy1, const vec2f other_xy2, const vec2f other_vel) const;

};