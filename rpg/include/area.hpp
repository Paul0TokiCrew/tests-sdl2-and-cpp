#pragma once



#include <vector>
#include <utility>
#include <vec2f.hpp>



class area_manager {
private:
	std::vector<std::pair<vec2f, vec2f>> rec_areas;

public:
	area_manager() { }
	~area_manager() { }

	void register_rec_area(const vec2f xy, const vec2f wh);

};