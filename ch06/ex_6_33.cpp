#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void func(const vector<int> &v,int i) {
	if (i < v.size()) {
		cout << v[i] << endl;
		func(v,++i);
	}	
}

int main()
{
	vector<int> v {1,2,3,4,5,6,7,8,9};
	func(v,0);
	return 0;
}