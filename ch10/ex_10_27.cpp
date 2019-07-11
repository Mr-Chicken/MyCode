#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::back_inserter;

int main()
{
	vector<int> vec {1,2,2,3,4,4,4,4,5,5};
	list<int> lst;

	unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));
	for (const auto &x : lst) 
		cout << x << " ";
	cout << endl;
	return 0;
}