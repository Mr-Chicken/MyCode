#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> num {2, 4, 6, 8, 10};
	std::modulus<int> mod;
	int div = 2;
	auto isDivisible = std::any_of(num.begin(), num.end(), [&](const int &i) {
		return mod(i, div) == 0;
	});
	cout << (isDivisible ? "True" : "False") << endl;
	return 0;
}