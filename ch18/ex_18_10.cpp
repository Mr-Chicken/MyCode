/**
	不处理异常版本，处理版本请看 ex_18_9.cpp
*/

#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::logic_error;
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cin;
using std::istream;

class out_fo_stock : public std::runtime_error {
public:
	explicit out_fo_stock(const std::string &s): runtime_error(s) {}
};
class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s): std::logic_error(s) {}
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):
		logic_error(s), left(lhs), right(rhs) {}
	const string left, right;
};

class Sales_data {
	friend ostream& operator<<(ostream &os, const Sales_data &s);
	friend istream& operator>>(istream &is, Sales_data &s);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
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
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
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
	os << s.bookNo << " " << s.units_sold << " " << s.revenue << "" << s.avg_price();
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


int main()
{
	Sales_data item1, item2;
	while (std::cin >> item1 >> item2) {
		item1 += item2;
	}	
	return 0;
}