#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cin;
using std::istream;
class Sales_data {
	friend ostream& operator<<(ostream &os, const Sales_data &s);
	friend istream& operator>>(istream &is, Sales_data &s);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
	friend bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
public:
	Sales_data() = default;
	Sales_data(const string &isbn, unsigned sold, double rev): bookNo(isbn), units_sold(sold), revenue(rev) {}
	Sales_data(const string &isbn): Sales_data(isbn, 0, 0.0){};
	string isbn() const {return bookNo;}
	Sales_data& operator+=(const Sales_data &rhs);
	Sales_data& operator-=(const Sales_data &rhs);

private:
	inline double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_data& Sales_data::operator-=(const Sales_data &rhs) {
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const {
	return units_sold ? revenue/units_sold : 0.0;
}

ostream& operator<<(ostream &os, const Sales_data &s) {
	os << s.bookNo << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return os;
}
istream& operator>>(istream &is, Sales_data &s) {
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	if (is)
		s.revenue = price * s.units_sold;
	else
		s = Sales_data();
	return is;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret += rhs;
	return ret;
}
Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret -= rhs;
	return ret;
}
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.bookNo < rhs.bookNo;
}

struct matches {
	vector<Sales_data>::size_type index;
	vector<Sales_data>::const_iterator begin;
	vector<Sales_data>::const_iterator end;
	matches(vector<Sales_data>::size_type ind, vector<Sales_data>::const_iterator beg, vector<Sales_data>::const_iterator ed):
		index(ind), begin(beg), end(ed) {}
};

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) 
			ret.push_back(matches(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}
