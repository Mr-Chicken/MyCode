#include <iostream>
using std::cout;
using std::endl;

void print(const int &a) {
	cout << a << endl;
}

void print(const int (&arr)[2]) {
	for (int a : arr) 
		cout << a << endl;
}


int main()
{
	int i = 0, j[2] = {0,1};

	print(i);
	print(j);	
	return 0;
}