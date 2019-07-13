#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec {1,2,3,4,5,6,7,8,9};

	for (auto r_it = vec.crbegin(), r_end = vec.crend(); r_it != r_end; ++r_it)
		cout << *r_it << " ";
	cout << endl;
	return 0;
}