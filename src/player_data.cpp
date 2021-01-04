#include <player_data.hpp>



void player_data::change_current_data(const int new_data) {
	if (new_data < this->min || new_data > this->max)
		return;

	this->current_data = new_data;
}