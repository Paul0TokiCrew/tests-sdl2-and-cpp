#pragma once



#include <cstddef>



class player_data {
private:
	int current_data;
	const int min, max;

public:
	player_data(const int min, const int max) :
	current_data(min), min(min), max(max) { }
	player_data(const int data, const int min, const int max) :
	current_data(data), min(min), max(max) { }
	~player_data() { }

	int get_current_data() const { return this->current_data; }

	void change_current_data(const int new_data);

	bool equals(const int comp) const;
	bool not_equals(const int comp) const;
	bool greater(const int comp) const;
	bool smaller(const int comp) const;
	bool greater_or_equals(const int comp) const;
	bool smaller_or_equals(const int comp) const;

};