#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

	vector<int> vec(std::begin(ia), std::end(ia));
	list<int> lt(std::begin(ia), std::end(ia));

	auto itv = vec.begin();
	while (itv != vec.end()) {
		if (*itv % 2 == 0)
			itv = vec.erase(itv);
		else
			++itv;
	}

	auto itl = lt.begin();
	while (itl != lt.end()) {
		if (*itl % 2 != 0)
			itl = lt.erase(itl);
		else 
			++itl;
	}

	cout << "Vector: ";
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;

	cout << "List: ";
	for (const auto &x : lt)
		cout << x << " ";
	cout << endl;
	return 0;
}