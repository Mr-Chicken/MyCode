#include <iostream>
#include <bitset>
#include <vector>
using std::cout;
using std::endl;
using std::bitset;
using std::vector;
int main()
{
	bitset<32> bs;
	vector<int> iv {1, 2, 3, 5, 8, 13, 21};
	for (const auto &x : iv)
		bs.set(x);
	cout << bs << endl;
	return 0;
}