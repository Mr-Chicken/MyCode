#ifndef EX_15_3_H
#define EX_15_3_H
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Quote {
	friend bool operator!=(const Quote &lhs, const Quote &rhs);
public:
	Quote(): bookNo(string("")), price(0.0) { 
		cout << "Quote()" << endl;
	}
	Quote(const string &book, double sales_price):
		bookNo(book), price(sales_price) {}
	Quote(const Quote &q): bookNo(q.bookNo), price(q.price) {
		cout << "Quote(const Quote &q)" << endl;
	}
	Quote(Quote &&q) noexcept :bookNo(q.bookNo), price(q.price)  {
		cout << "Quote(Quote &&q)" << endl;
	}
	Quote& operator=(const Quote &q) {
		bookNo = q.bookNo;
		price = q.price;
		cout << "Quote& operator=(const Quote &q)" << endl;
		return *this;
	}
	Quote& operator=(Quote &&q) noexcept {
		if (*this != q) {
			bookNo = q.bookNo;
			price = q.price;
		}
		cout << "Quote& operator=(Quote &&q)" << endl;
		return *this;
	}
	string isbn() const {return bookNo;}
	virtual double net_price(std::size_t n) const 
		{return n * price;}
	virtual void debug() const {
		cout << "ISBN: " << bookNo << " price: " << price << endl; 
	}
	virtual ~Quote() {
		cout << "~Quote()" << endl;
	}
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

inline bool operator!=(const Quote &lhs, const Quote &rhs) {
	return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}
#endif

class Bulk_quote : public Quote {
public:
	Bulk_quote(): Quote(), min_qty(0), discount(0.0) {
		cout << "Bulk_quote()" << endl;
	}
	Bulk_quote(const string &book, double sales_price, size_t qty, double disc):
		Quote(book, sales_price), min_qty(qty), discount(disc) {}
	Bulk_quote(const Bulk_quote &b): Quote(b), min_qty(b.min_qty), discount(b.discount) {
		cout << "Bulk_quote(const Bulk_quote &b)" << endl;
	}
	Bulk_quote(Bulk_quote &&b): Quote(std::move(b)), min_qty(b.min_qty), discount(b.discount) {
		cout << "Bulk_quote(Bulk_quote &&b)" << endl;
	}
	Bulk_quote& operator=(const Bulk_quote &b) {
		Quote::operator=(b);
		min_qty = b.min_qty;
		discount = b.discount;
		cout << "Bulk_quote& operator=(const Bulk_quote &b)" << endl;
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote &&b) noexcept {
		if (*this != b) {
			Quote::operator=(std::move(b));
			min_qty = b.min_qty;
			discount = b.discount;
			cout << "Bulk_quote& operator=(Bulk_quote &&b)" << endl;
		}
		return *this;
	}
	~Bulk_quote() override {
		cout << "~Bulk_quote()" << endl;
	}
	double net_price(std::size_t cnt) const override {
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};


int main()
{
	Bulk_quote b;

	return 0;
}