#include <iostream>
class Date {
public:
    Date(int y = 0, int m = 0, int d = 0): year(y), month(m), day(d){}
    Date(std::istream &is) {is >> year >> month >> day;}
private:
    int year;
    int month;
    int day;
};
