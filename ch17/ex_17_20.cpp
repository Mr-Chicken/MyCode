#include <regex>
#include <iostream>
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

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	while (std::getline(std::cin, s)) {
		for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
		}
	}
	return 0;
}