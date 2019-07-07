#include <algorithm>
#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::endl;
using std::string;

int main()
{
	list<string> lst {"Hello","Hello","Hello","Hello","World!"};
	cout << std::count(lst.cbegin(), lst.cend(), "Hello") << endl;
	return 0;
}