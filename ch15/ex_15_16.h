#ifndef EX_15_16_H
#define EX_15_16_H
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

class LimitQuote : public Disc_quote{
public:
	LimitQuote() = default;
	LimitQuote(const string &isbn, double sales, std::size_t max, double disc):
		Disc_quote(isbn, sales, max, disc){}
	double net_price(std::size_t cnt) const override {
		if (cnt >= quantity) 
			return (1 - discount) * quantity * price + (cnt - quantity) * price;
		else
			return (1 - discount) * cnt * price;
	}
};

#endif