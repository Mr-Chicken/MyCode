#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
	vector<string> v;
	string str;
	while (cin >> str) v.push_back(str);
	for (string x : v) cout << x << endl; 
	return 0;
}