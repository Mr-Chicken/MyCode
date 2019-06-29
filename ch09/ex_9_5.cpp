#include <vector>
#include <iostream>
using std::cout;
using std::endl;

auto findNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end,const int &n) {
	while (begin != end) {
		if (n == *begin)
			return begin;
		++begin;
	}
	return end-1; // 返回最后一个元素的迭代器
}

int main() {
	std::vector<int> v {3,5,6,7,12,4,6};
	auto it = findNumber(v.begin(), v.end(), 3);
	cout << *it << endl;
	return 0;
}