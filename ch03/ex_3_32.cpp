#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
	constexpr size_t arraySize = 10;
	int arr[arraySize];
	for (size_t i = 0;i<arraySize;++i)
		arr[i] = i+1;
	
	// copy
	int cp[arraySize];
	for (size_t i = 0;i<arraySize;++i)
		cp[i] = arr[i];

	// vector

	std::vector<int> v1(arraySize,0);
	int x = 1;
	for (auto &y : v)
		y = x++;
	std::vector<int> v2(arraySize);
	v2 = v1;
	return 0;
}