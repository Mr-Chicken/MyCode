#include <list>
#include <vector>
#include <iostream>
using std::list;
using std::vector;
using std::string;

int main()
{
	list<const char*> lt {"A", "B", "C", "D"};
	vector<string> v;

	v.assign(lt.cbegin(), lt.cend());
	for (const auto &x : v)
		std::cout << x << std::endl;
	return 0;
}