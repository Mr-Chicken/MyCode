#include <iostream>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> lst {1,2,3,4,5,6};
	std::fill_n(lst.begin(), lst.size(), 0);
	for (const auto &x : lst)
		cout << x << " ";
	cout << endl;
	return 0;
}