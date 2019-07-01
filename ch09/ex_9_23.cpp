#include <vector>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	std::vector<int> c(1);

	if (!c.empty()) {

		// 他们都是第一个元素的值
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
		cout << val << " " << val2 << " " << val3 << " " << val4 << endl;
	}

	return 0;
}