#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int x;
	cin >> x;
	if (x%2 == 0)
		cout << x << " is a EVEN." << endl;
	else
		cout << x << " is a PARITY." << endl;

	return 0;
}