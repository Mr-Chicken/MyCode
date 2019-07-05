#include <iostream>
using std::cout;
using std::endl;
using std::string;

string addPreSuffix(string name, const string &pre, const string &su) {
	name.insert(0, pre);
	name.insert(name.size(), su);
	return name;
}

int main()
{
	cout << addPreSuffix("Jack", "Mr.", "Jr.") << endl;
	cout << addPreSuffix("Mary", "Ms.", "III") << endl;
	return 0;
}