#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a, b;
	cin >> a >> b;
	if (b == 0) throw std::runtime_error("Div by zero!");
	/*
		terminate called after throwing an instance of 'std::runtime_error'
 	what():  Div by zero!
	 */
	return 0;
}