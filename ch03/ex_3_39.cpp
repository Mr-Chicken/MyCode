#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	string s1("opposite");
	string s2("opposite");

	if (s1 == s2) 
		cout << "s1 == s2" << endl;
	else 
		cout << "s1 != s2" << endl;

	const char str1[] = "hello";
	const char str2[] = "world";

	if (strcmp(str1,str2) != 0) 
		cout << "str1 != str2" << endl;
	else
		cout << "str1 == str2" << endl;

	return 0;
}