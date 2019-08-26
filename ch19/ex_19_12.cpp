#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class Screen {
public:
	typedef string::size_type pos;
	static const pos Screen::*cur() {return &Screen::cursor;}
	static const string Screen::*data() {return &Screen::contents;}
	char get_cursor() const {return contents[cursor];}
	char get() const;
	char get(pos ht, pos wd) const;
private:
	string contents;
	pos cursor;
	pos height, width;
};

int main()
{
	Screen sc;
	const string::size_type Screen::*pdata = Screen::cur();
	auto cur = sc.*pdata;
	cout << cur << endl;
	return 0;
}