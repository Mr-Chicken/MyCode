#include <iostream>


class Sales_data {
friend std::istream& read(std::istream &is, Sales_data &sa);
public:
    Sales_data(std::string s = ""): bookNo(s) {}
    Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt) {}
    Sales_data(std::istream &is) {read(std::cin, *this);}
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream &is, Sales_data &sa) {
    is >> sa.bookNo >> sa.units_sold >> sa.revenue;
    return is;
}

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
    return 0;
}
