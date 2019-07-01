#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
	vector<string> vec;
	string word;
	auto itv = vec.begin();
	while (std::cin >> word)
		itv = vec.insert(itv, word);

	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
	
	return 0;
}