#include <iostream>
using std::cout;
using std::endl;

template <typename T, size_t sz>
void print(T (&arr)[sz]) {
	for (const auto &x : arr)
		cout << x << endl;
}

int main()
{
	int arr[10] {1,2,3,4,5,6,7,8,9,10};
	print(arr);
	return 0;
}