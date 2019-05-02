#include <iostream>

using std::endl;
using std::cout;

void f() {
	cout << "call f()" << endl;
}
void f(int i) {
	cout << "call f(int)" << endl;
}
void f(int i, int j) {
	cout << "call f(int, int)" << endl;
}
void f(double d, double d2 = 3.14) {
	cout << "call f(double, double = 3.14)" << endl;
}

int main()
{
	// f(2.56, 42);		ambiguous
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}