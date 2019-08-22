#include <regex>
#include <iostream>
using std::cout;
using std::endl;
using std::regex;
using std::smatch;
using std::string;
bool valid(const smatch &m) {
	if (m[2].matched)
		return m[3].matched;
	else
		return !m[3].matched;
}
int main()
{
	string phone = "(\\d{5})([-])?(\\d{4})?\\b";
	regex r(phone);
	string fmt = "$1-$3";
	smatch m;
	string s;
	while (std::getline(std::cin, s)) {
		for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
			if (valid(*it))
				cout << "valid: " << it->format(fmt) << endl;
			else
				cout << "not valid: " << it->str() << endl;
		}
	}
	return 0;
}