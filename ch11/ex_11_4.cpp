#include <iostream>
#include <map>
#include <cctype>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void processString(string &s) {
	// 删除标点
	auto it = s.begin();
	while (it != s.end()) {
		if (ispunct(*it)) {
			it = s.erase(it);
			continue;
		}
		*it = tolower(*it); // 忽略大小写
		++it;
	}

}

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		processString(word);
		++word_count[word];
	}

	for (const auto &x : word_count)
		cout << x.first << " occurs " << x.second <<(x.second > 1 ? " times" : " time" ) << endl;	
	return 0;
}