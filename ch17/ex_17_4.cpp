#include <iostream>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
using std::tuple;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::get;
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
typedef tuple<vector<Sales_data>::size_type,
				vector<Sales_data>::const_iterator,
				vector<Sales_data>::const_iterator> matches;
vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) 
			ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files) {
	string s;
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << "not found in any stores" << endl;
			continue;
		}
		for (const auto &store : trans) 
			os << "store: " << std::get<0>(store) << " sales: " 
			<< std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s))
			<< endl;
	}
}

int main()
{
	vector<vector<Sales_data>> file {
		{
			Sales_data("012-99201", 10, 100), 
			Sales_data("012-99201", 9, 90)
		},
		{
			Sales_data("011-8123", 8, 4),
			Sales_data("011-8123", 10, 5)
		}
	};
	reportResults(std::cin, std::cout, file);
	return 0;
}