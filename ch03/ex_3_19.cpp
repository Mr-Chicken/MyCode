#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;


int main()
{
	vector<int> v1{42,42,42,42,42,42,42,42,42,42};
	vector<int> v2(10,42); // the better one
	vector<int> v3;
	for (unsigned x = 1; x <= 10;++x)
		v3.push_back(x);
	return 0;
}