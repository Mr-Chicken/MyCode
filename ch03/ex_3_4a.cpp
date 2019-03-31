#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2) {
		if (s1 == s2) 
			cout << s1 << " and "+s2 << " are equal!" << endl;
		else
			cout << "The larger string is: " << (s1>s2? s1: s2) << endl;
	}
	return 0;
}