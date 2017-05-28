#include "error.h"

void fatalError(std::string msg) {
	std::cout << msg << std::endl;
	std::string tmp;
	std::cin >> tmp;
	exit(1);
}