#include <unordered_map>
#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;;
using std::istringstream;
using std::ifstream;
using std::getline;
using std::unordered_map;

unordered_map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("no rule for" + key);
	}
	return trans_map;
}

const string& transform(const string &s, const unordered_map<string, string> &m) {
	auto it = m.find(s);
	if (it != m.cend())
		return it->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstWord = true;
		while (stream >> word) {
			if (firstWord)
				firstWord = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, const char *argv[])
{
	unordered_map<string, size_t> word_count;
	string word;
	while (std::cin >> word)
		++word_count[word];

	for (const auto &x : word_count)
		cout << x.first << " occurs " << x.second << (x.second > 1 ? " times" : " time") << endl;

	// 单词转换程序 P391
	// use "./a.out trans_map input"
	ifstream map_file(argv[1]);
	ifstream input(argv[2]);
	word_transform(map_file, input);
	return 0;
}
