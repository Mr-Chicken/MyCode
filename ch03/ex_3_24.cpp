#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main()
{
	vector<int> v;
	int n;
	while (cin >> n) v.push_back(n); 	

	for (auto it = v.cbegin();it != v.cend()-1;++it)
		cout << *it + *(it+1) << endl;
	cout << "---------------" << endl;
	for (auto beg = v.cbegin(), lst = v.cend() - 1;beg != v.cend();++beg,--lst)
		cout << *beg + *lst << endl;
	return 0;
}