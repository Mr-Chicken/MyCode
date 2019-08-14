#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
using std::cout;
using std::endl;

template <typename iter, typename value>
iter find(iter beg, iter end, const value &v) {
	while (beg != end && *beg != v) ++beg;
	return beg;
}

int main()
{
	vector<int> vec {1,2,3,4,5,6};
	cout << *find(vec.begin(), vec.end(), 5) << endl;
	list<int> lst {5,6,7,8,9,10};
	cout << *find(lst.begin(), lst.end(), 6) << endl;
	return 0;
}