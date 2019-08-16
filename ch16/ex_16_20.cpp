#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template <typename T>
void print(const T& cont) {
	for (auto beg = cont.begin(), end = cont.end(); beg != end; ++beg)
		cout << +beg << " ";
	cout << endl;
}

int main()
{
	vector<int> v {1,2,3,4,5};
	print(v);
	return 0;
}