#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

inline void addMember(map<string, vector<string>> &family, const string &familyName,const vector<string> &names) {
	family[familyName] = names;
}

void printFamily(map<string, vector<string>> &family) {
	for (const auto &x : family) {
		cout << x.first << ": ";
		for (const auto &y : x.second)
			cout << y << " ";
		cout << endl;
	}
}
int main()
{
	map<string, vector<string>> family;
	addMember(family, "Joe", {"Npra", "Jile", "Pike"});
	printFamily(family);
	return 0;
}