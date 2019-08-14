#include <iostream>
using std::cout;
using std::endl;

template <typename T, size_t sz>
T* begin(T (&arr)[sz]) {
	return arr;
}
template <typename T, size_t sz>
T* end(T (&arr)[sz]) {
	return arr + sz;
}

int main()
{
	int arr[10] {1,2,3,4,5,6,7,8,9,10};
	cout << *begin(arr) << endl;
	return 0;
}