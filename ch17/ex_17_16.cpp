#include <iostream>
#include <regex>
using std::regex;
using std::cout;
using std::endl;
using std::string;
using std::smatch;
int main()
{
	regex r("[^c]ei");
	smatch results;

	string word;
	while (std::cin >> word) {
		if (regex_search(word, results, r))
			cout << "illegal word: " << word << endl;
		else
			cout << "legal word: " << word << endl;
	}
	return 0;
}