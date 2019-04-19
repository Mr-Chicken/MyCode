#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> ivec {4,2,5,9,1,40};
	std::vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0;
			ix != ivec.size();ix++,cnt--)
		ivec[ix] = cnt;
	for (int &x : ivec)
		cout << x << endl;
	return 0;
}