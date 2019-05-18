#include <iostream>
class Sales_data {
friend std::istream& read(std::istream &is, Sales_data &sa);
public:
    Sales_data(std::string s = ""): bookNo(s) {}
    Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt) {}
    Sales_data(std::istream &is = std::cin) {is >> bookNo >> units_sold >> revenue;} // here
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
