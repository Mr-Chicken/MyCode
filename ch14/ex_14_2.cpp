#include <iostream>
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
public:
	Sales_data() = default;
	Sales_data(const string &isbn, unsigned sold, double rev): bookNo(isbn), units_sold(sold), revenue(rev) {}
	Sales_data(const string &isbn): Sales_data(isbn, 0, 0.0);
	string isbn() const {return bookNo;}
	Sales_data& operator+=(const Sales_data &rhs);

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

inline double avg_price() const {
	return units_sold ? revenue/units_sold : 0.0;
}

ostream& operator<<(ostream &os, const Sales_data &s) {
	os << s.bookNo << " " << s.units_sold << " " << s.revenue << "" << s.avg_price();
	return os;
}
istream& operator>>(istream &is, Sales_data &s) {
	is >> s.bookNo >> s.units_sold >> s.revenue;
	return is;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret += rhs
	return ret;
}