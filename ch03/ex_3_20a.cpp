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
	while (cin >>x) v.push_back(x);

	for (decltype(v.size()) x = 0; x < v.size()-1;++x) {
		cout << v[x] + v[x+1] << endl;
	} 
	return 0;
}