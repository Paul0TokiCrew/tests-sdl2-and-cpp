#pragma once



#include <iostream>
#include <vector>
#include <string>



class log {
private:
	log() { }
	static std::vector<std::string*> status;

public:
	static void add_status(std::string* stat);
	static void log_status();

};
