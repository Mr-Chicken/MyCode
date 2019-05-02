#include <iostream>
using std::endl;
using std::cout;
using std::string;

inline bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

int main()
{
	string s1("alps");
	string s2("hima alaya");

	cout << isShorter(s1,s2) << endl;
	return 0;
}