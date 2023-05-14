#include <iostream>

#include "table.h"

int main(int argc, char** argv) {
	table<int> test(2, 3);
	test[1][2];

	return 0;
}