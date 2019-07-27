#include "ex_13_30.h"

#include <vector>
#include <algorithm>
using std::vector;

int main()
{
	vector<HasPtr> vec;
	vec.push_back(HasPtr("apple"));
	vec.push_back(HasPtr("banana"));
	vec.push_back(HasPtr("pear"));
	vec.push_back(HasPtr("dear"));
	std::sort(vec.begin(), vec.end());
	return 0;
}