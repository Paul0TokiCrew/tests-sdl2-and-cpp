#pragma once



#include <iostream>
#include <vector>
#include <string>



class debugger {
private:
	debugger() { }
	static std::vector<std::string*> status;

public:
	static void add_status(std::string* stat);
	static void debug();

};