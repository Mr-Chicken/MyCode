#include <iostream>
using std::ostream;
using std::istream;
using std::endl;
using std::cout;
class Date {
	friend ostream& operator<<(ostream &os, const Date &d);
	friend istream& operator>>(istream &is, Date &d);
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
istream& operator>>(istream &is, Date &d) {
	is >> d.year >> d.month >> d.day;
	if (!is)
		d = Date();
	return is;
}
int main()
{
	Date d;
	std::cin >> d; 
	cout << d << endl;	
	return 0;
}