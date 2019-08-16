#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
template <std::string::size_type,std::string::size_type> class Screen;
template <std::string::size_type ht, std::string::size_type wd>
ostream& operator<<(ostream &os, const Screen<ht, wd> &sc);
template <std::string::size_type ht, std::string::size_type wd>
istream& operator>>(istream &is, Screen<ht, wd> &sc);

template <std::string::size_type ht, std::string::size_type wd>
class Screen {
	friend ostream& operator<<<ht, wd>(ostream &os, const Screen<ht, wd> &sc);
	friend istream& operator>><ht, wd>(istream &is, Screen<ht, wd> &sc);
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(char c): height(ht), width(wd), contents(ht * wd, c) {}
	char get() const {
		return contents[cursor];
	}
	Screen& move(pos r, pos c);
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

template <std::string::size_type ht, std::string::size_type wd>
ostream& operator<<(ostream &os, const Screen<ht, wd> &sc) {
	cout << sc.contents << endl;
	return os;
}
template <std::string::size_type ht, std::string::size_type wd>
istream& operator>>(istream &is, Screen<ht, wd> &sc) {
	std::cin >> sc.contents;
	return is;
}

template <std::string::size_type ht, std::string::size_type wd>
inline Screen<ht, wd>& Screen<ht, wd>::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

int main()
{
	Screen<10, 10> sc('A');
	cout << sc.get() << endl;
	return 0;
}