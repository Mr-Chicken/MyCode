#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;

void elimDups(list<string> &words) {
	words.sort();
	words.unique();
}

int main()
{
	list<string> words {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "thurtle"};
	elimDups(words);
	for (const auto &x : words)
		cout << x << " ";
	cout << endl;
	return 0;
}