#include <iostream>
using std::cout;
using std::endl;

template <typename T, size_t sz>
constexpr size_t size(T (&arr)[sz]) {
	return sz;
}

int main()
{
	int arr[10] = {0};
	cout << size(arr) << endl;
	return 0;
}