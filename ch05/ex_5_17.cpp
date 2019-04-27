#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
	std::vector<int> v1 {0,1,1,2};
	std::vector<int> v2 {0,1,1,2,3,5,8};

	bool isPrefix = true;
	if (v1.size() < v2.size()) {
		for (auto it1 = v1.begin(), it2 = v2.begin();
				it1 != v1.end();
					++it1, ++it2) {
			if (*it1 != *it2) isPrefix = false;
		}
	}
	cout << isPrefix << endl;
	return 0;
}