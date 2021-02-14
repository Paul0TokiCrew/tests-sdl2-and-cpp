#pragma once



#include <vector>
#include <utility>
#include <vec2f.hpp>



class area_manager {
private:
    std::vector<std::pair<vec2f, vec2f>> objs;

public:
    area_manager() { }
    ~area_manager() { }

};