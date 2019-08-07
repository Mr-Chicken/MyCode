#ifndef EX_15_7_H
#define EX_15_7_H
#include "ex_15_3.h"
class LimitQuote : public Quote{
public:
	LimitQuote() = default;
	LimitQuote(const string &isbn, double sales, std::size_t max, double disc):
		Quote(isbn, sales), max_qty(max), discount(disc) {}
	double net_price(std::size_t cnt) const override {
		if (cnt >= max_qty) 
			return (1 - discount) * max_qty * price + (cnt - max_qty) * price;
		else
			return (1 - discount) * cnt * price;
	}
private:
	std::size_t max_qty;
	double discount;
};

#endif