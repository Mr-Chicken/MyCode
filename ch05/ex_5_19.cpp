#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	string s1;
	string s2;

	do {
		cout << "Please enter two strings: ";
		cin >> s1 >> s2;
		cout << (s1<s2? s1: s2) << endl;
	} while (cin);

	return 0;
}