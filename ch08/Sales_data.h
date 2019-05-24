#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Sales_data {

friend istream& read(istream &is, Sales_data &ss);
friend ostream& print(ostream &os, const Sales_data &ss);
friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(string isbn, unsigned sold, double rev): bookNo(isbn), units_sold(sold), revenue(rev){}
    Sales_data(string isbn): Sales_data(isbn, 0, 0.0){}
    Sales_data(istream &is) {is >> bookNo >> units_sold >> revenue;}

    Sales_data& combine(const Sales_data&);
    const string& isbn() {return bookNo;}
    double avg_price() const;
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& read(istream &is, Sales_data &ss);
ostream& print(ostream &os, const Sales_data &ss);
Sales_data add(const Sales_data&, const Sales_data&);

#endif
