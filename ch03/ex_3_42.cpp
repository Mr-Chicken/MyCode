#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v {2,3,4,5,7,1,2};

	int arr[v.size()];
	auto it = v.begin();
	for (int &x : arr)
		x = *it++;

	for (int x : arr)
		cout << x << " ";
	cout << endl;
	return 0;
}