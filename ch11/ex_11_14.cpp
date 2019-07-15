#include <iostream>
#include <map>
#include <vector>
#include <utility>
using std::pair;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

inline 
void addMember(map<string, vector<pair<string, string>>> &family, const string &familyName, const vector<pair<string, string>> &par) {
	family[familyName] = par;
}

void printFamily(map<string, vector<pair<string, string>>> &family) {
	for (const auto &x : family) {
		cout << x.first << ": " << endl;
		for (const auto &y : x.second)
			cout << "\t" << y.first << " " << y.second << endl;
	}
}
int main()
{
	map<string, vector<pair<string, string>>> family;
	addMember(family, "Joe", {{"Pike", "10 9,1942"}, {"Mary", "3 9, 1823"}});
	printFamily(family);
	return 0;
}