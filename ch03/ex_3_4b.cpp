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
		if (s1.size() == s2.size()) 
			cout << s1 << " and "+s2 << " have the same size!" << endl;
		else
			cout << "The longer string is: " << (s1.size()>s2.size()? s1: s2) << endl;
	}
	return 0;
}