#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec {1,2,3,4,5,6,7,8,9};

	for (auto it = vec.cend(), end = vec.cbegin(); it != end; )
		cout << *--it << " ";
	cout << endl;
	return 0;
}