#ifndef EX_15_15_H
#define EX_15_15_H
#include "ex_15_3.h"
class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double price, std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(std::size_t cnt) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double price, std::size_t qty, double disc):
		Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t cnt) const override {
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
};
#endif