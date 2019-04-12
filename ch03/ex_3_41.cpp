#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
int main()
{
	int int_arr[] {2,3,5,7,11,13,17,19};

	vector<int> v(begin(int_arr),end(int_arr));
	for (int x : v) cout << x << " ";
	cout << endl;
	

	return 0;
}