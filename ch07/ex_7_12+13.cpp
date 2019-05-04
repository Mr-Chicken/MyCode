#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::cin;

struct Sale_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sale_data(istream &in);
	Sale_data& combine(const Sale_data &rhs);
	string isbn() const {return bookNo;};
};

Sale_data& Sale_data::combine(const Sale_data &rhs) {
	revenue *= units_sold;
	units_sold += rhs.units_sold;
	revenue += rhs.revenue * rhs.units_sold;
	return *this;
}

istream& read(istream &in, Sale_data &d) {
	in >> d.bookNo >> d.units_sold >> d.revenue;
	return in;
}
void print(ostream &out, const Sale_data &d) {
	out << d.bookNo << " " << d.units_sold << " " 
		<< d.revenue/d.units_sold << endl;
}

Sale_data::Sale_data(istream &in) {
	read(in, *this);
}

int main()
{
	Sale_data total(cin);
	if (!total.bookNo.empty()) {
		istream &is = cin;
		while (is) {
			Sale_data trans(cin);
			if (trans.isbn() == total.isbn())
				total.combine(trans);
			else {
				print(cout, total);
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		print(cout, total);
	}
	return 0;
}
