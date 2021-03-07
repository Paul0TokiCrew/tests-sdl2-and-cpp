#include <log.hpp>



int main(int argc, char* argv[]) {
	std::string stat = "eae";
	log::add_status(&stat);
	log::log_status();
	return 0;
}
