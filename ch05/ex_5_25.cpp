#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a, b;
	cin >> a >> b;
	try {
		if (b == 0) throw std::runtime_error("Div by zero!");
		cout << a/b << endl;
	}
	catch (std::runtime_error err) {
		cout << err.what() << endl
		  << "Try again?(y/n): ";
		char c;
		cin >> c;
		if (!cin && c == 'n') return 0;
		else {
			cin >> a >> b;
			cout << a/b << endl;
		}
	}
	return 0;
}