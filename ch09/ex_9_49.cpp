#include <iostream>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

int main() {
	ifstream in("letters");
	if (!in.is_open()) return -1;

	string condit = "acemnorsuvwxz";
	string::size_type pos = 0;
	string word;
	string longest;
	
	while (in >> word) {
		if (word.find_first_not_of(condit, pos) == string::npos) 
			longest = (word.size() > longest.size() ? word : longest);
		++pos;
	}

	in.close();
	cout << longest << endl;
	return 0;
}