#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int ia[3][4] {
		{9,5,2,45},
		{9,1,25,9},
		{3,1,5,124}
	};
	
	// version 1
	for (auto &p : ia){
		for (auto &x : p) {
			cout << x << " ";
		}
		cout << endl;
	}

	// version 2 
	for (auto x = 0;x < 3;++x) {
		for (auto y = 0;y < 4;++y)
			cout << ia[x][y] << " ";
		cout << endl;
	}

	// version 3
	for (auto *p = ia;p != ia + 3;++p) {
		for (auto *q = *p;q != *p + 4;++q) 
			cout << *q << " ";
		cout << endl;
	}
	return 0;
}