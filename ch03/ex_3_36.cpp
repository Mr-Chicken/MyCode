#include <iterator>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
	int arr1[] {4,12,2,645,7,1224};
	int arr2[] {3,1,2,4,124,5,12,5};

	bool isEqual = false;
	if (begin(arr1) - end(arr1) != begin(arr2) - end(arr2))
		isEqual = false;
	for (auto p1 = begin(arr1),p2 = begin(arr2);p1 != end(arr1);++p1,++p2)
		if (*p1 != *p2) isEqual = false;
	if (isEqual) {
		cout << "Two arrays are equal!" << endl;
	} else {
		cout << "Two arrays aren't equal!" << endl;
	}

	std::vector<int> v1 {1,3,4,351,212,3};
	std::vector<int> v2 {6,1,23,6,434,6,78};

	if (v1 == v2) {
		cout << "Two vectors are equal!" << endl;
	} else {
		cout << "Two vectors aren't equal!" << endl;
	}
	return 0;
}