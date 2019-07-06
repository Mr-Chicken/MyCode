#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Date {
public:
	Date() = default;
	Date(const string &dt);
	void show() {
		cout << year << " " << month << " " << day << endl;
	}
private:
	unsigned year = 0;
	unsigned day = 0;
	unsigned month = 0;
};

int main()
{
	Date d("Oct 1 1949");
	d.show();
	return 0;
}

Date::Date(const string &dt) {
	string::size_type lastPosCutting = dt.find_last_of(",/ ");
	++lastPosCutting; // 使substr返回的string不包括 ",/ "
	year = stoi(dt.substr(lastPosCutting));
	string::size_type firstPosCutting = dt.find_first_of(",/ ");
	++firstPosCutting;// 如上 不包括 ",/ "
	lastPosCutting -= 2; // 使substr 不包括 前后两个 ",/ "
	day = stoi(dt.substr(firstPosCutting, lastPosCutting));
	string monthStr = dt.substr(0, firstPosCutting);
	if (monthStr.find("Jan") != string::npos)      month = 1;
	else if (monthStr.find("Feb") != string::npos) month = 2;
	else if (monthStr.find("Mar") != string::npos) month = 3;
	else if (monthStr.find("Apr") != string::npos) month = 4;
	else if (monthStr.find("May") != string::npos) month = 5;
	else if (monthStr.find("Jun") != string::npos) month = 6;
	else if (monthStr.find("Jul") != string::npos) month = 7;
	else if (monthStr.find("Aug") != string::npos) month = 8;
	else if (monthStr.find("Sept")!= string::npos) month = 9;
	else if (monthStr.find("Oct") != string::npos) month = 10;
	else if (monthStr.find("Nov") != string::npos) month = 11;
	else if (monthStr.find("Dec") != string::npos) month = 12;
	if (month == 0)
		month = stoi(monthStr);
}