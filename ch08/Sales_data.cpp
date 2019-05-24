#include "Sales_data.h"

inline
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}


Sales_data& Sales_data::combine(const Sales_data &ss) {
    units_sold += ss.units_sold;
    revenue += ss.revenue;
    return *this;
}

istream& read(istream &is, Sales_data &ss) {
    is >> ss.bookNo >> ss.units_sold >> ss.revenue;
    return is;
}

ostream& print(ostream &os, const Sales_data &ss) {
    os << ss.bookNo << " " << ss.units_sold << " " << ss.avg_price()
        << endl;
    return os;
}

Sales_data add(const Sales_data &sa, const Sales_data &sd) {
    Sales_data sum = sa;
    sum.combine(sd);
    return sum;
}

void Sales_data::writeDown(ostream &os) {
    os << bookNo << " " << units_sold << " " << revenue << endl;
}
