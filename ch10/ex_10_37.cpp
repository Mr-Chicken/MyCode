#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec {1,2,3,4,5,6,7,8,9,10};

	list<int> cplst(vec.rbegin() + 3, vec.rend() - 2);

	for (const auto &x : cplst)
		cout << x << " ";
	cout << endl;
	return 0;
}