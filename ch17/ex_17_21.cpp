#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using std::vector;
using std::cout;
using std::endl;
using std::regex;
using std::smatch;
using std::string;
bool valid(const smatch &m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4] == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	while (getline(std::cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})");
	for (const auto &entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			smatch m;
			if (std::regex_match(nums, m, r)) {
				if (!valid(m))
					badNums << " " << nums;
				else
					formatted << " " << m.str();
			}
			if (badNums.str().empty())
				cout << entry.name << " " << formatted.str() << endl;
			else
				std::cerr << "input error: " << entry.name << " invalid number(s): " << badNums.str() << endl;
		}
	}
	return 0;
}