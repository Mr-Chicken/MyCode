#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
	vector<string> text {"hello","nice","to","meet","you"};

	auto it = text.begin();
	for (decltype(it->size()) x = 0;x < it->size();++x) {
		(*it)[x] = toupper((*it)[x]);
	}
	for (;it != text.cend();++it) 
		cout << *it << endl;
	return 0;
}