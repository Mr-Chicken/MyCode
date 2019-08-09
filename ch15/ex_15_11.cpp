#ifndef EX_15_3_H
#define EX_15_3_H
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price):
		bookNo(book), price(sales_price) {}
	string isbn() const {return bookNo;}
	virtual double net_price(std::size_t n) const 
		{return n * price;}
	virtual void debug() const {
		cout << "ISBN: " << bookNo << " price: " << price << endl; 
	}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

inline double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
};

#endif