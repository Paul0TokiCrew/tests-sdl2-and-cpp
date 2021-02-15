#pragma once



#include <vector>
#include <utility>
#include <tuple>
#include <vec2f.hpp>



class area_manager {
private:
	std::vector<std::pair<vec2f, vec2f>> areas;

public:
	area_manager() { }
	~area_manager() { }

	void register_rec(const vec2f xy1, const vec2f xy2);

	bool check_collision(const vec2f other_xy1, const vec2f other_xy2) const;

};