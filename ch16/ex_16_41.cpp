#include <iostream>
template <typename T>
auto sum(const T &a, const T &b) -> decltype(a + b){
	return a + b;
}

int main()
{
	std::cout << sum(10, 210012) << std::endl; 
	return 0;
}