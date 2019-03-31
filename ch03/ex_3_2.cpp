#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string line; //null str
	getline(cin,line);
	cout << line << endl;
	cin >> line;
	cout << line << endl;
	return 0;
}