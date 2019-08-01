#include <iostream>
using std::ostream;
using std::endl;
using std::cout;
class Date {
	friend ostream& operator<<(ostream &os, const Date &d);
public:
    Date(int y = 0, int m = 0, int d = 0): year(y), month(m), day(d){}
    Date(std::istream &is) {is >> year >> month >> day;}
private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream &os, const Date &d) {
	os << d.year << " " << d.month << " " << d.day;
	return os;
}
int main()
{
	Date d(1976, 12, 10);
	cout << d << endl;	
	return 0;
}