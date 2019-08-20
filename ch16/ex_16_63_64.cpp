#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
template <typename T>
size_t count(const vector<T> &cont, T val) {
	size_t ret = 0;
	for (const auto &x : cont)
		if (x == val) ++ret;
	return ret;
}

template <>
size_t count(const vector<const char*> &cont, const char* val) {
	size_t ret = 0;
	for (const auto &x : cont)
		if (string(x) == string(val)) ++ret;
	return ret;
}
int main()
{
	vector<double> dvec {0.2, 0.2, 0.5, 3.141};
	vector<int> ivec{1,1,1,4,5};
	vector<const char*> svec {"he", "he", "she"};
	cout << count(dvec, 0.2) << endl;
	cout << count(ivec, 1) << endl;
	cout << count(svec, "he") << endl;

	return 0;
}