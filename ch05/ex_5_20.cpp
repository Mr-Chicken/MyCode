#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	string bef;
	string cur;

	do {
		cout << "Please enter a string: ";
		cin >> cur;
		if (!bef.empty() && cur == bef) break;
		else bef = cur;
	} while (cin);

	if (bef != cur) 
		cout << "NO-SAME-WORD" << endl;

	return 0;
}