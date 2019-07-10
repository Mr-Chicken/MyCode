#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

int main()
{
	int v = 42;
	auto f = [&v]() -> bool {
		if (v--) return true;
		else return false;
	};

	cout << f() << endl;
	v = 0;
	cout << f() << endl;
	return 0;
}
