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
};

const string& isbn(const Sale_data &d) {
	return d.bookNo;
}

void combine(Sale_data &d1, const Sale_data &d2) {
	Sale_data dat;
	dat.bookNo = d1.bookNo;
	dat.units_sold = d1.units_sold + d2.units_sold;
	dat.revenue = ( (d1.units_sold * d1.revenue) + (d2.units_sold * d2.revenue) ) / dat.units_sold;
	d1 = dat;
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
			if (isbn(trans) == isbn(total))
				combine(total, trans);
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