#include <set>
#include "../ch10/Sales_data.h"

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
	return sd1.isbn().size() < sd2.isbn().size();
}
using Compare = bool (*)(const Sales_data &sd1, const Sales_data &sd2);

std::multiset<Sales_data, Compare> bookstore(compareIsbn);
std::multiset<Sales_data, Compare>::iterator it = bookstore.begin();