#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> nv;

	cout << nv.at(0) << endl;
	cout << nv[0] << endl;
	cout << nv.front() << endl;
	cout << *(nv.begin()) << endl;	

	/**
		terminate called after throwing an instance of 'std::out_of_range'
		what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0) 
	*/
	return 0;
}