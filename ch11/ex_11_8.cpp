#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec {1,2,2,2,3,4,5,6,6,6,7,7,9};
	std::sort(vec.begin(), vec.end());
	auto end_unique = std::unique(vec.begin(), vec.end());

	vec.erase(end_unique, vec.end());
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
	return 0;
}