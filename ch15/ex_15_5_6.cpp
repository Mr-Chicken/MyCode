#include "ex_15_3.h"
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
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

int main()
{
	Bulk_quote bq("129-9381", 5.0, 10, 0.3);
	print_total(cout, bq, 3000);
	return 0;
}