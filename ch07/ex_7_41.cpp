#include <iostream>
using std::cout;
using std::string;
using std::endl;

class Sales_data {
public:
    Sales_data(): Sales_data("", 0, 0.0) {cout << "Sales_data()" << endl;}
    Sales_data(string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(price)
        { cout << "Sales_data(string s, unsigned cnt, double price)" << endl; }
    Sales_data(string s): Sales_data(s, 0, 0.0) {cout << "Sales_data(string s)" << endl;}
    Sales_data(std::istream &is)
        { is >> bookNo >> units_sold >> revenue; }
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


int main() {
    Sales_data s1;
    Sales_data s2("x-12-123");
    Sales_data s3("la-124-49", 10, 100);
    return 0;
}
