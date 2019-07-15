#include <utility>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;

int main()
{
	vector<pair<string, int>> vec;
	string s;
	int a;
	while (std::cin >> s && std::cin >> a) {
		vec.push_back(make_pair(s, a));
		// vec.push_back({s,a});
		// vec.push_back(pair<string, int>(s,a));
		// vec.emplace_back(s, a);
	}
	for (const auto &x : vec) 
		cout << x.first << ":" << x.second << endl;
	return 0;
}