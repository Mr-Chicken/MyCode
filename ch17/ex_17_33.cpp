#include <random>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>
using std::cout;
using std::map;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline (map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("no rule for " + key);
	return trans_map;
}

const string & trans_form(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;

	static std::default_random_engine e(time(0));
	static std::bernoulli_distribution b;

	while (std::getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstWord = true;
		while (stream >> word) {
			bool dontTrans = b(e);
			if(firstWord)
				firstWord = false;
			else
				cout << " ";
			if (dontTrans)
				cout << word;
			else
				cout << trans_form(word, trans_map);
		}
	}
}


int main()
{
	ifstream map_file("../ch11/trans_map");
	ifstream inp("../ch11/input");
	word_transform(map_file, inp);
	return 0;
}