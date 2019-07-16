#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
	map<string, size_t> word_count;
	string word;
	while (std::cin >> word) {
		auto it = word_count.insert({word, 1});
		if (!it.second)
			++it.first->second;
	}

	for (const auto &x :word_count)
		cout << x.first << " occurs " << x.second << ((x.second > 1) ? " times" : "time") << endl;
	return 0;
}