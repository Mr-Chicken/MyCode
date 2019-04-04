#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> v;
	int x = 0;
	while (cin >> x) v.push_back(x);

	int size = v.size();
	for (decltype(size) x = 0; x < size;++x) {
		cout << v[x] + v[size-1-x] << endl;
	}

	return 0;
}