#include <iostream>
class Date {
public:
    Date(): Date(0, 0, 0) {}
    Date(int y, int m, int d): year(y), month(m), day(d){}
    Date(std::istream &is) {is >> year >> month >> day;}
private:
    int year = 0;
    int month = 0;
    int day = 0;
};
