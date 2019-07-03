#include <forward_list>
#include <list>
#include <iostream>

using std::forward_list;
using std::list;
using std::advance;
using std::cout;
using std::endl;

int main()
{
	list<int> iList {0,1,2,3,4,5,6,7,8,9};
	forward_list<int> iForwardList {0,1,2,3,4,5,6,7,8,9};

	// Using list:
	auto it = iList.begin();
	while (it != iList.end()) {
		if (*it % 2) {
			it = iList.insert(it, *it);
			advance(it, 2);
		} else {
			it = iList.erase(it);
		}
	}
	
	cout << "list: ";
	for (const auto &x : iList)
		cout << x << " ";
	cout << endl;

	// Using forward_list:
	auto curr = iForwardList.begin();

	while (curr != iForwardList.end()) {
		if (*curr % 2) {
			curr = iForwardList.insert_after(curr, *curr);
			advance(curr, 2);
		} else {
			curr = iForwardList.erase_after(curr);
		}
	}
	cout << "forward_list: ";
	for (const auto &x : iList)
		cout << x << " ";
	cout << endl;
	return 0;
}