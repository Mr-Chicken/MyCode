#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string s = "Hello World!";
	for (auto &c : s)
		c = 'X';
	/*
		for (char &c :s) 
			c = 'X';
	*/
	cout << s << endl;
	return 0;
}