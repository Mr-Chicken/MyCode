#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::isupper;
int main()
{
	string bef;
	string cur;

	do {
		cout << "Please enter a string: ";
		cin >> cur;
		if (!bef.empty() && isupper(cur[0]) &&cur == bef) break;
		else bef = cur;
	} while (cin);

	if (bef != cur) 
		cout << "NO-SAME-WORD" << endl;

	/* or use `continue`
		while (cin >> cur) {
			if (!isupper(cur[0])) continue;
			if (!bef.empty() && cur == bef) break;
			else bef = cur;
		}
	 */

	return 0;
}