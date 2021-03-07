#include <log.hpp>



std::vector<std::string*> log::status;

void log::add_status(std::string* stat) {
	log::status.push_back(stat);
}

void log::log_status() {

	for (auto i : log::status)
		std::cout << *i << std::endl;

}
