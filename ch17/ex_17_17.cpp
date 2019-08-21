#include <regex>
#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::regex;

int main()
{
	vector<std::string> exp {"neighbor", "albeit"};
	regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::string file = "receipt freind theif receive";
	for (std::sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
		if (std::find_if(exp.begin(), exp.end(), [&](const std::string &s) -> bool {
			return s == it->str();
		}) != exp.end())  {continue;}
		cout << it->str() << endl;
	}

	return 0;
}