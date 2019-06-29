#include <list>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	std::list<int> ls {1,2,3,4,5};
	std::vector<int> vec {10,11,12,13,14};

	std::vector<double> v1(ls.begin(), ls.end());
	for (const auto & x : v1) 
		cout << x << endl;

	std::vector<double> v2(vec.begin(), vec.end());
	for (const auto & x : v2) 
		cout << x << endl;
	return 0;
}