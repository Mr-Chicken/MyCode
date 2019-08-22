#include <iostream>
#include <regex>
using std::cout;
using std::endl;
using std::string;
using std::smatch;
using std::regex;
int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	while (std::getline(std::cin, s))
		cout << regex_replace(s, r, fmt) << endl;
	return 0;
}