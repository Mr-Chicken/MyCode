#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> v {3,9,5,1,55,23,41,43};

	for (auto it = v.begin();it != v.end();++it)
		*it *= *it;
	for (auto it = v.cbegin();it != v.cend();++it)
		cout << *it << endl;
	return 0;
}