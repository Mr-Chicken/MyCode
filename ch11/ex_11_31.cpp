#include <map>
#include <iostream>

using std::multimap;
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

	auto it = authors.find("Weimin");
	if (it == authors.end())
		return -1;
	else 
		authors.erase(it);
	for (const auto &x : authors) {
		cout << x.first << ": " << x.second << endl;
	}

	return 0;
}