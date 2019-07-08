#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const std::string &isbn): Sales_data(isbn, 0, 0.0) {}
	Sales_data(const std::string &isbn, unsigned sold, double rev): bookNo(isbn), units_sold(sold), revenue(rev){}
	const std::string& isbn() const {return bookNo;}

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif

