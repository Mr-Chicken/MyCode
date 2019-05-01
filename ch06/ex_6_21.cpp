#include <iostream>
using std::cout;
using std::endl;

int max(const int a, const int *b) {
	return a>(*b)? a: *b;
}

int main()
{
	int arr[] {1,4,2,5,6,5,7,9,10};

	cout << max(9,arr + 4) << endl;
	return 0;
}