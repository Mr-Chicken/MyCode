#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
	vector<int> vec {1,2,3,4,5,6,7,8,9,10};
	cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	return 0;
}