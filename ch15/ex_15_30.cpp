#include "ex_15_3.h"
#include <memory>
#include <set>
using std::shared_ptr;
using std::multiset;
class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double sales_price, size_t qty, double disc):
		Quote(book, sales_price), min_qty(qty), discount(disc) {}
	double net_price(std::size_t cnt) const override {
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	Bulk_quote* clone() const & {return new Bulk_quote(*this);}
	Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

class Basket {
public:
	void add_item(const Quote &sale) {
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote &&sale) {
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(std::ostream &os) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<shared_ptr<Quote>, decltype(compare)*> items {compare};
};
double Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend();iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	cout << "Total Sale: " << sum << endl;
}

int main()
{
	Basket b;
	b.add_item(Quote("12-3821", 10.0));
	b.add_item(Quote("12-3821", 10.0));
	b.add_item(Bulk_quote("7723-99", 5.0, 10, 0.4));
	b.add_item(Bulk_quote("7723-99", 5.0, 10, 0.4));
	b.total_receipt(cout);
	return 0;
}