#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Sales_item.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::find;


int main()
{
	vector<Sales_item> records;
	Sales_item cur;
	while (cin >> cur)
		records.push_back(cur);

	std::sort(records.begin(), records.end(), compareIsbn);

	auto it = records.begin();
	auto last = it;
	while (it != records.end()) {
		last = std::find_if(it, records.end(), [it](const Sales_item &s) {
			return !(s.isbn() == it->isbn());
		});
		Sales_item sum =  std::accumulate(it, last, Sales_item());
		cout << sum;
		cout << endl;
		it = last;
	}
	return 0;
}