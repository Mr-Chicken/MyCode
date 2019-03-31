#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string cur, next;
	while (cin >> next) cur += next;
	cout << cur << endl;
	return 0;
}