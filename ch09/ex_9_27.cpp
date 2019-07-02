#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;
using std::forward_list;

int main()
{
	forward_list<int> fl {0,1,2,3,4,5,6,7,8,9};

	auto prev = fl.before_begin();
	auto curr = fl.begin();

	while (curr != fl.end()) {
		if (*curr %2 != 0) 
			curr = fl.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}

	for (const auto &x : fl)
		cout << x << " ";
	cout << endl;
	return 0;
}