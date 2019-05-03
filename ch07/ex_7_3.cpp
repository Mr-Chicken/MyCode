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

	Sale_data& combine(const Sale_data &rhs);
	string isbn() const {return bookNo;};
};

Sale_data& Sale_data::combine(const Sale_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream &in, Sale_data &d) {
	in >> d.bookNo >> d.units_sold >> d.revenue;
	return in;
}
void print(ostream &out, const Sale_data &d) {
	out << d.bookNo << " " << (d.units_sold * d.revenue) << " " 
		<< (d.units_sold * d.revenue) / d.units_sold << endl;
}

int main()
{
	Sale_data total;
	if (read(cin, total)) {
		Sale_data trans;
		while (read(cin, trans)) {
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
