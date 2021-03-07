#include <log.hpp>



void log::add_status(std::string* stat) {
	log::status.push_back(stat);
}

void log::debug() {

	for (auto i : log::status)
		std::cout << *i << std::endl;

}
