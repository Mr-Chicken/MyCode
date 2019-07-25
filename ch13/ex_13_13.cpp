#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
struct X {
	X() {cout << "X()" << endl;}
	X(const X&) {cout << "X(const X&)" << endl;}
	X& operator=(const X&) {cout << "operator=(const X&)" << endl; return *this;}
	~X() {cout << "~X()" << endl;}
};

void func(const X &a, X b) {}
int main() {
	X a, b;
	X c = a;
	func(a, b);
	X *p = new X;
	delete p;
	vector<X> vec {a, b};
	return 0;
}