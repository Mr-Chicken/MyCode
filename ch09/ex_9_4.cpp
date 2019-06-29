#include <vector>
#include <iostream>
using std::cout;
using std::endl;

bool findNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end,const int &n) {
	while (begin != end) {
		if (n == *begin)
			return true;
		++begin;
	}
}

int main() {
	std::vector<int> v {3,5,6,7,12,4,6};
	cout << (findNumber(v.begin(), v.end(), 4)? "true":"false") << endl;
	return 0;
}