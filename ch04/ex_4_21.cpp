#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> v {4,1,9,5,7,18};
	for (auto &x : v)
		x = x%2 ? x : x*x;
	for (const int &x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}