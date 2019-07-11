#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>

using std::deque;
using std::cout;
using std::endl;
using std::copy;

void print(const deque<int> &de) {
	for (const auto &x : de)
		cout << x << " ";
	cout << endl;
}

int main()
{
	deque<int> de {1,2,3,4,5,6,7,8,9};
	deque<int> d1, d2, d3;
	copy(de.begin(), de.end(), std::back_inserter(d1));
	copy(de.begin(), de.end(), std::inserter(d2, d2.begin()));
	copy(de.begin(), de.end(), std::front_inserter(d3));

	print(d1);
	print(d2);
	print(d3);

	return 0;
}