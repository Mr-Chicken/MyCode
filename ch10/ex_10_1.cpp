#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec {1,2,3,4,2,2,6,8,9,0};
	cout << std::count(vec.cbegin(), vec.cend(), 2) << endl;
	return 0;
}