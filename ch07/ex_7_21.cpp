#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(std::istream&);
    const std:: string& isbn() {return bookNo;}
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const
        { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
Sales_data::Sales_data(std::istream& is) {
    is >> bookNo >> units_sold >> revenue;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
std::istream& read(std::istream& is, Sales_data& data) {
    is >> data.bookNo >> data.units_sold >> data.revenue;
    return is;
}
std::ostream& print(std::ostream& os, const Sales_data &data) {
    os << data.bookNo << " " << data.units_sold << " " << data.avg_price() << endl;
    return os;
}

Sales_data add(const Sales_data& d1, const Sales_data& d2) {
    Sales_data sum = d1;
    sum.combine(d2);
    return sum;
}


int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total);
                total = trans;
            }
        }
    } else {
        std::cerr << "No data?!" << endl;
    }
    return 0;
}
