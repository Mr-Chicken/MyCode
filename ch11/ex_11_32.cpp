#include <map>
#include <set>
#include <iostream>

using std::multimap;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::string;
int main()
{
	multimap<string, string> authors {
		{"Weimin", "World"},
		{"Weimin", "My Clothes"},
		{"Tony", "Flowers"},
		{"Tony", "Mike's Park"}
	};
	map<string, set<string>> author;
	set<string> books;

	for (auto beg = authors.begin(), end = authors.end(); beg != end; ++beg) {
		author[beg->first].insert(beg->second);
	}

	for (const auto &x : author) {
		cout << x.first << ": ";
		for (const auto &book : x.second)
			cout << book << " ";
		cout << endl;
	}
}