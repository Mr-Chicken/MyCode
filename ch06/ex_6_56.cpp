#include <iostream>
#include "ex_6_55.h"

using std::endl;
using std::cout;

std::vector<func> v {addition, subtraction, mucation, division};
int main() {
	int a = 10, b = 5;

	for (const auto &f : v) {
		cout << f(a, b) << endl;
	}

	return 0;
}