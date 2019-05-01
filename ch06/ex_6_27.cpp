#include <iostream>
#include <initializer_list>
using std::cout;
using std::endl;
using std::initializer_list;
int sum(initializer_list<int> il) {
	int sum = 0;
	for (const int & i : il)
		sum += i;
	return sum;
}

int main()
{
	cout << sum({5,2,4,9}) << endl;
	return 0;
}