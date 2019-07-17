#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::istringstream;
using std::ifstream;
using std::getline;

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
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

const string& transform(const string &s, const map<string, string> &m) {
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
	// use "./a.out trans_map input"
	ifstream map_file(argv[1]);
	ifstream input(argv[2]);
	word_transform(map_file, input);
	return 0;
}