#include <player_data.hpp>



void player_data::change_current_data(const int new_data) {
	if (new_data < this->min || new_data > this->max)
		return;

	this->current_data = new_data;
}

bool player_data::equals(const int comp) const {
	if (this->current_data == comp)
		return true;

	return false;
}

bool player_data::not_equals(const int comp) const {
	if (this->current_data != comp)
		return true;

	return false;
}

bool player_data::greater(const int comp) const {
	if (this->current_data > comp)
		return true;

	return false;
}

bool player_data::smaller(const int comp) const {
	if (this->current_data < comp)
		return true;

	return false;
}

bool player_data::greater_or_equals(const int comp) const {
	if (this->current_data >= comp)
		return true;

	return false;
}

bool player_data::smaller_or_equals(const int comp) const {
	if (this->current_data <= comp)
		return true;

	return false;
}