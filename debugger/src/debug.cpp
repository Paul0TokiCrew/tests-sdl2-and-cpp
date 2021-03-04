#include <debug.hpp>



void debugger::add_status(std::string* stat) {
	debugger::status.push_back(stat);
}

void debugger::debug() {

	for (auto i : debugger::status)
		std::cout << *i << std::endl;

}