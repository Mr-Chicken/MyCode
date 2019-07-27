#include <iostream>
#include <string>
using std::string;
class HasPtr {
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) {++*use;}
	~HasPtr() {
		if (--*use == 0) {
			delete ps;
			delete use;
		}
	}
	HasPtr& operator=(const HasPtr &rhs) {
		++*rhs.use;
		if (--*use == 0) {
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
private:
	string *ps;
	int i;
	size_t *use;
};

int main()
{
	HasPtr p("HasPtr");	
	return 0;
}