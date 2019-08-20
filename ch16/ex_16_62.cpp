#include <iostream>
#include <unordered_set>
#include <functional>
using std::unordered_set;
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cin;
using std::istream;
// template <typename> class hash;
class Sales_data {
    friend std::hash<Sales_data>;
    friend ostream& operator<<(ostream &os, const Sales_data &s);
    friend istream& operator>>(istream &is, Sales_data &s);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
public:
    Sales_data() = default;
    Sales_data(const string &isbn, unsigned sold, double rev): bookNo(isbn), units_sold(sold), revenue(rev) {}
    Sales_data(const string &isbn): Sales_data(isbn, 0, 0.0){};
    string isbn() const {return bookNo;}
    Sales_data& operator+=(const Sales_data &rhs);
    Sales_data& operator=(const string &isbn);
    Sales_data& operator-=(const Sales_data &rhs);
private:
    inline double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

namespace std {
    template <>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const;
    };
    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
    }
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}
Sales_data& Sales_data::operator=(const string &isbn) {
    units_sold = 0;
    revenue = 0.0;
    bookNo = isbn;
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}
Sales_data& Sales_data::operator-=(const Sales_data &rhs) {
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
    return units_sold ? revenue/units_sold : 0.0;
}

ostream& operator<<(ostream &os, const Sales_data &s) {
    os << s.bookNo << " " << s.units_sold << " " << s.revenue << "" << s.avg_price();
    return os;
}
istream& operator>>(istream &is, Sales_data &s) {
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    if (is)
        s.revenue = price * s.units_sold;
    else
        s = Sales_data();
    return is;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret;
    ret.units_sold = lhs.units_sold + rhs.units_sold;
    ret.revenue = lhs.revenue + rhs.revenue;
    return ret;
}
Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret = lhs;
    ret -= rhs;
    return ret;
}

int main()
{
    unordered_set<Sales_data> us {Sales_data("012-312"), Sales_data("012-312", 10, 300)};
    for (const auto &x : us)
        cout << x << endl;
    return 0;
}