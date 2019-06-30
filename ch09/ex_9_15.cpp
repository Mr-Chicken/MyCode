#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> v1 {1,2,3,4,5}, v2 {1,2,3,5,4};

	std::cout << (v1 == v2? "true" : "false") << std::endl;
	return 0;
}