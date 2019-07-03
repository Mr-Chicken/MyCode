#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vi {1,2,3,4,5,6,7,8,9,10};
	auto iter = vi.begin();
	// 修正如下 (添加了花括号)，应在insert之后在执行一次递增操作，否则会导致死循环。
	while (iter != vi.end()) {
		if (*iter % 2)
			iter = vi.insert(iter, *iter), ++iter;
		++iter;
	}

	for (const auto &x : vi)
		cout << x << " ";
	cout << endl;
	return 0;
}