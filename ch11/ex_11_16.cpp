#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
	map<int, string> mp;
	mp[10] = "aa";
	auto it = mp.begin();
	it->second = "bb";
	cout << it->second << endl;
	return 0;
}