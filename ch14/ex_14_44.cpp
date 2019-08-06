#include <functional>
#include <iostream>
#include <map>
using std::map;
using std::cout;
using std::endl;
using std::string;

int add(int a, int b);
struct divide
{	
	int operator()(int a, int b) {
		return a / b;
	}
};

int main()
{
	std::modulus<int> mod;
	auto mius = [](int a, int b) {
		return a - b;
	};
	map<string, std::function<int(int, int)>> binops = {
		{"+", add},
		{"-", mius},
		{"*", [](int a, int b) {return a*b;}},
		{"/", divide()},
		{"%", mod}
	};
	cout << binops["+"](5,5) << endl;
	cout << binops["*"](12, 12) << endl;
	return 0;
}

int add(int a, int b) {
	return a + b;
}