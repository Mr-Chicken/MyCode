#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> v;
	int n = 0;
	while (cin >> n) v.push_back(n);
	for (int x : v) cout << x << endl; 
	return 0;
}