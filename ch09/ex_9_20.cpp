#include <list>
#include <deque>
#include <iostream>

using std::list;
using std::cout;
using std::endl;
using std::deque;

int main()
{
	list<int> ils {1,2,3,4,5,6};
	deque<int> ida;
	deque<int> idb;

	for (const auto &x : ils) {
		if (x%2 == 0)
			ida.push_back(x);
		else
			idb.push_back(x);
	}	

	cout << "偶数: ";
	for (const auto &x : ida)
		cout << x << " ";
	cout << endl;

	cout << "奇数: ";
	for (const auto &x : idb)
		cout << x << " ";
	cout << endl;
	return 0;
}