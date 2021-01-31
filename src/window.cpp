#include <window.hpp>

int window::get_refresh_rate() const {
	int display_index = SDL_GetWindowDisplayIndex(this->win);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(display_index, 0, &mode);

	return mode.refresh_rate;
}

void window::clear() const {
	SDL_RenderClear(this->ren);
}

void window::clear(const int r, const int g, const int b) const {
	SDL_SetRenderDrawColor(this->ren, r, g, b, 255);
	SDL_RenderClear(this->ren);
}

void window::clear(const int r, const int g, const int b, const int a) const {
	SDL_SetRenderDrawColor(this->ren, r, g, b, a);
	SDL_RenderClear(this->ren);
}

void window::update() const {
	SDL_RenderPresent(this->ren);
}