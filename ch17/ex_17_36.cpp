#include <iostream>
#include <iomanip>
#include <cmath>
using std::uppercase;
using std::hexfloat;
using std::endl;
using std::cout;
using std::left;
using std::setw;

int main()
{
	cout << uppercase << hexfloat;
	for (int i = 1; i <= 100; ++i)
		cout << "sqrt " << i << setw(30) << sqrt(i) << endl;

	return 0;
}