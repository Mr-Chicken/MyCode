#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string s = "Hello World!";

	// while
	decltype(s.size()) x = 0;
	while (x < s.size()) {
		s[x] = 'X';
		++x;
	}
	cout << s << endl;
	// for -> i think this can be beter
	for (decltype(s.size()) x =0;x < s.size();++x) s[x] = 'X';
	cout << s << endl;
	return 0;
}