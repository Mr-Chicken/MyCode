#include <iostream>
using std::cout;
using std::endl;

void swap(int *p1,int *p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main()
{
	int a = 3;
	int b = 20;

	swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}