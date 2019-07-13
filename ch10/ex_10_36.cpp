#include <iostream>
#include <algorithm>
#include <list>

using std::list;
using std::cout;
using std::endl;
using std::string;

int main()
{
	list<int> vec {1,2,3,4,5,6,7,0,8,9};

	auto it = std::find(vec.rbegin(), vec.rend(), 0);
	cout << *it << endl;
	return 0;
}