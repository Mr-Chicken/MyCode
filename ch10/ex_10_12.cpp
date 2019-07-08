#include "Sales_data.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
	return sd1.isbn().size() < sd2.isbn().size();
}

int main(int argc, char const *argv[])
{
	vector<Sales_data> vec{Sales_data("1"), Sales_data("22"), Sales_data("333")};
	std::sort(vec.begin(), vec.end(), compareIsbn);
	for (const auto &x : vec)
		cout << x.isbn() << " ";
	cout << endl;
	return 0;
}