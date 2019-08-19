#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
template <typename T>
ostream& print(ostream &os, const T &t) {
	return os << t;
}
template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
	os << t << ", ";
	return print(os, rest...);
}
int main()
{
	int i = 2;
	string s("Hello");
	print(cout, i , s, 42);
	return 0;
}