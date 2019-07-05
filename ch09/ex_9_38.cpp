#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

inline void showStauts(const vector<int> &vec) {
	cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
}

int main()
{
	vector<int> vec;
	for (int x = 0; x<100;++x) {
		vec.push_back(x);
		showStauts(vec);
	} // 翻倍增加capacity的值 
	return 0;
}