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
	for (int (&p)[4] : ia){
		for (int &x : p) {
			cout << x << " ";
		}
		cout << endl;
	}

	// version 2 
	for (size_t x = 0;x < 3;++x) {
		for (size_t y = 0;y < 4;++y)
			cout << ia[x][y] << " ";
		cout << endl;
	}

	// version 3
	for (int (*p)[4] = ia;p != ia + 3;++p) {
		for (int *q = *p;q != (*p) + 4;++q) 
			cout << *q << " ";
		cout << endl;
	}
	return 0;
}