#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;
using std::string;

int main()
{
	list<string> id;
	string word;
	while (std::cin >> word)
		id.insert(id.begin(), word);

	for (const auto &x : id)
		cout << x << endl;
	return 0;
}