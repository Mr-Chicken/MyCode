#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
	vector<string> v;
	string word;
	while (cin >> word) v.push_back(word);

	for (auto & x : v) { // x is a string
		for (decltype(x.size()) y = 0;y < x.size();++y)
			x[y] = toupper(x[y]);
	}

	for (auto &x : v) 
		cout << x << endl;
	return 0;
}