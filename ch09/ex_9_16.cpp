#include <iostream>
#include <list>
#include <vector>

using std::vector;
using std::list;

int main()
{
	list<int> lt {1,2,3,5,4};
	
	vector<int> v1 {1,2,3,4,5};
	vector<int> v2;
	v2.assign(lt.cbegin(), lt.cend());

	std::cout << (v1 == v2? "true" : "false") << std::endl;
	return 0;
}