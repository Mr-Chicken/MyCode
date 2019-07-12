#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream_iterator;
int main()
{
	vector<int> vec;
	istream_iterator<int> int_iter(cin), eof;
	std::copy(int_iter, eof, std::back_inserter(vec));
	std::sort(vec.begin(), vec.end());
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
	return 0;
}