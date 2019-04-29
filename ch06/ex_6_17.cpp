#include <iostream>
#include <string>
using std::isupper;
using std::tolower;
using std::cout;
using std::endl;
using std::string;

bool haveUpper(const string &s) {
	for (const char &c : s) {
		if (isupper(c)) return true;
	}
	return false;
}

void allToLower(string &s) {
	for (char &c : s) {
		c = tolower(c);
	}
}

int main()
{
	string s("Pop");
	cout << haveUpper(s) << endl;
	allToLower(s);
	cout << s << endl;
	return 0;
}