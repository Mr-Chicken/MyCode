#include <iostream>
#include <string>
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

	Sale_data() = default;
	Sale_data(const string &s) : bookNo(s){}
	Sale_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p){}
	Sale_data(istream &in);

	Sale_data& combine(const Sale_data &rhs);
	string isbn() const {return bookNo;};
};


Sale_data& Sale_data::combine(const Sale_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream &in, Sale_data &d) {
	double price = 0;
	cin >> d.bookNo >> d.units_sold >> price;
	d.revenue = price * d.units_sold;
	return in;
}

ostream& print(ostream &out, const Sale_data &d) {
	out << d.isbn() << " " << d.units_sold << " " << d.revenue << " " << d.revenue/d.units_sold
		<< endl;
	return out;
}

Sale_data add(const Sale_data &lhs, const Sale_data &rhs) {
	Sale_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sale_data::Sale_data(istream &in) {
	read(in, *this);
}


int main()
{
	Sale_data s1;
	Sale_data s2(cin);
	Sale_data s3("x-20bamz");
	Sale_data s4("x-20bamz", 9, 31.9);

	print(cout, s1);
	print(cout, s2);
	print(cout, s3);
	print(cout, s4);
	return 0;
}