#include <iostream>

#include "table.h"

int main(int argc, char** argv) {
	auto test = table<int>(2, 3);
	test[1][2] = 10;
	std::cout << test[1][2];

	return 0;
}