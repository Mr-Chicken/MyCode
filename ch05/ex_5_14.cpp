#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string cur;
	string bef;
	unsigned cnt = 1;
	unsigned max = 0;
	
	cin >> bef;
	while (cin >> cur) {
		if (bef == cur) 
			++cnt;
		else {
			if (cnt > max) max = cnt;
			bef = cur;
		}
	}

	cout << max << endl;
	return 0;
}