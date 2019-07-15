#include <iostream>
#include <set>
#include "../ch10/Sales_data.h"
#include <vector>

using std::multiset;
using std::cout;
using std::endl;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
	return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
	using Compare = bool(*)(const Sales_data &sd1, const Sales_data &sd2);
	multiset<Sales_data, Compare> bookstore(compareIsbn);
	return 0;
}