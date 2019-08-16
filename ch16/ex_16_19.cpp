#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template <typename T>
void print(const T& cont) {
	for (typename T::size_type beg = 0, end = cont.size(); beg != end; ++beg)
		cout << cont[beg] << " ";
	cout << endl;
}

int main()
{
	vector<int> v {1,2,3,4,5};
	print(v);
	return 0;
}