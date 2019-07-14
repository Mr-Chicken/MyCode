#include <iostream>
#include <map>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	map<string, size_t> word_count;
	string word;

	while (cin >> word)
		++word_count[word];

	for (const auto &x : word_count)
		cout << x.first << " occurs " << x.second <<(x.second > 1 ? " times" : " time" ) << endl;	
	return 0;
}