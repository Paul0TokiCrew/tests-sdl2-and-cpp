#include <character.hpp>



int character::x = 0, character::y = 140,
	character::w = 64, character::h = 64;



void character::move_up() {

	for (int i = 0; i < 15; ++i)
		--character::y;

}

void character::move_down() {

	for (int i = 0; i < 15; ++i)
		++character::y;

}

void character::move_right() {

	for (int i = 0; i < 15; ++i)
		++character::x;

}

void character::move_left() {

	for (int i = 0; i < 15; ++i)
		--character::x;

}