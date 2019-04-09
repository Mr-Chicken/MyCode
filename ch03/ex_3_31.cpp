#include <iostream>

using std::cout;
using std::endl;

int main()
{
	constexpr size_t arraySize = 10;
	int arr[arraySize];
	for (size_t i = 0;i<arraySize;i++)
		arr[i] = i+1;
	for (int x : arr)
		cout << x << " ";
	cout << "\b" <<endl;
	return 0;
}