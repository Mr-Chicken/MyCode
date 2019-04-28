#include <iostream>

using std::endl;
using std::cout;

void reset(int &i) {
	i = 0;
}

int main()
{
	int j = 123;
	reset(j);
	cout << j << endl;
	return 0;
}