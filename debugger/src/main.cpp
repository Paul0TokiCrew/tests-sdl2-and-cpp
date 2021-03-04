#include <debug.hpp>



int main(int argc, char* argv[]) {
	std::string stat = "eae";
	debugger::add_status(&stat);
	debugger::debug();
	return 0;
}