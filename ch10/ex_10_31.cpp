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
using std::ostream_iterator;
int main()
{
	vector<int> vec;
	istream_iterator<int> int_iter(cin), eof;
	ostream_iterator<int> out_int(cout, " ");

	while (int_iter != eof)
		vec.push_back(*int_iter++);

	std::sort(vec.begin(), vec.end());
	std::unique_copy(vec.begin(), vec.end(), out_int);
	cout << endl;
	return 0;
}