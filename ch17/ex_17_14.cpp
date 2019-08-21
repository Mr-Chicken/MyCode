#include <regex>
#include <iostream>
using std::cout;
using std::endl;
using std::regex;
int main()
{
	try {
		regex r1("[[:alnum:]+\\.(cpp|cxx|cc$");
	} catch (std::regex_error e) {
		cout << e.what() << "\ncode:"  << e.code() << endl;
	}
	try {
		regex r1("[[:alnum:]]+\\.(cpp|cxx|cc$");
	} catch (std::regex_error e) {
		cout << e.what() << "\ncode:"  << e.code() << endl;
	}
	return 0;
}