#include <deque>
#include <iostream>

using std::deque;
using std::cout;
using std::endl;
using std::string;

int main()
{
	deque<string> id;
	string word;
	while (std::cin >> word)
		id.push_back(word);

	for (const auto &x : id)
		cout << x << endl;
	return 0;
}