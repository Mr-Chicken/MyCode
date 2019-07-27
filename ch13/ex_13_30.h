#ifndef EX_13_30_H
#define EX_13_30_H
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class HasPtr {
	friend void swap(HasPtr &p1, HasPtr &p2);
	friend bool operator<(const HasPtr &p1, const HasPtr &p2);
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	~HasPtr() {delete ps;}
	HasPtr(const HasPtr &hp) {
		i = hp.i;
		ps = new string(*hp.ps);
	}
	HasPtr& operator=(HasPtr hp) {
		swap(*this, hp);
		return *this;
	}
private:
	string *ps;
	int i;
};

void swap(HasPtr &p1, HasPtr &p2) {
	using std::swap;
	swap(p1.ps, p2.ps);
	swap(p1.i, p2.i);
	cout << "call swap(HasPtr &p1, HasPtr &p2)" << endl;
}


bool operator<(const HasPtr &p1, const HasPtr &p2) {
	return *p1.ps < *p2.ps;
}
#endif