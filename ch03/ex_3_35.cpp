#include <iterator>
#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	int arr[10];
	int *p = begin(arr);
	int *last = end(arr);

	while (p != last){
		*p = 0;
		++p;
	}
	for (int a : arr)
		cout << a << endl;
	return 0;
}