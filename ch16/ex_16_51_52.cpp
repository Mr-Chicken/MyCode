#include <iostream>
using std::cout;
using std::endl;
using std::string;
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {
	cout << "template parameter packet: " << sizeof...(Args) << endl;
	cout << "function parameter packet: " << sizeof...(rest) << endl;
}

int main()
{
	int i = 0;
	double d = 3.14;
	string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	return 0;
}