#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string s;
	cin >> s;
	if (!s.empty()) {
		for (auto &c : s)
			if (!ispunct(c)) cout << c;
	}
	return 0;
}