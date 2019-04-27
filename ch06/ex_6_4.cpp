#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void interaction() {
	int val;
	while (cin >> val) {
		int ret = 1;
		while (val > 1)
		ret *= val--;
		cout << ret << endl;
	}
}

int main()
{
	interaction();
	return 0;
}