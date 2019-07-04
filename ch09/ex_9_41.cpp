#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<char> vec {'H','e','l','l','o',' ','W','o','r','l','d'};

	std::string s(vec.begin(), vec.end());
	cout << s << endl;
	return 0;
}