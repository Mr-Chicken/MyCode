#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> v {1,2,3,4,5,6,7,8,9,10};
	auto begin = v.begin();

	while (begin != v.end()) {
		++begin;
		v.insert(begin, 42);
		++begin;
	}

	for (const auto &x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}