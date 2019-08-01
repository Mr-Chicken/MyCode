#include <iostream>
using std::ostream;
using std::istream;
using std::endl;
using std::cout;
class Date {
	friend ostream& operator<<(ostream &os, const Date &d);
	friend istream& operator>>(istream &is, Date &d);
	friend Date operator+(const Date &lhs, const Date &rhs);
	friend Date operator-(const Date &lhs, const Date &rhs);
public:
    Date(int y = 0, int m = 0, int d = 0): year(y), month(m), day(d){}
    Date(std::istream &is) {is >> year >> month >> day;}
    Date& operator+=(const Date &rhs);
    Date& operator-=(const Date &rhs);
private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream &os, const Date &d) {
	os << d.year << " " << d.month << " " << d.day;
	return os;
}
istream& operator>>(istream &is, Date &d) {
	is >> d.year >> d.month >> d.day;
	if (!is)
		d = Date();
	return is;
}
Date& Date::operator+=(const Date &rhs) {
	year += rhs.year;
	month += rhs.month;
	day += rhs.day;
	return *this;
}
Date& Date::operator-=(const Date &rhs) {
	year -= rhs.year;
	month -= rhs.month;
	day -= rhs.day;
	return *this;
}
Date operator+(const Date &lhs, const Date &rhs) {
	Date ret = lhs;
	ret += rhs;
	return ret;
}
Date operator-(const Date &lhs, const Date &rhs) {
	Date ret = lhs;
	ret -= rhs;
	return ret;
}
int main()
{
	Date d;
	std::cin >> d; 
	Date sub;
	std::cin >> sub;
	cout << d - sub << endl;	
	return 0;
}