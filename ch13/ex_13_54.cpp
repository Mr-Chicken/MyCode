#include <iostream>
using std::string;
class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	HasPtr(HasPtr &&h) noexcept: i(h.i), ps(h.ps){
		h.ps = nullptr;
	}
	~HasPtr() {delete ps;}
	HasPtr& operator=(HasPtr &&hp) noexcept {
		if (this != &hp) {
			i = std::move(hp.i);
			ps = hp.ps;
			hp.ps = nullptr;
		}
		return *this;
	}
	HasPtr& operator=(HasPtr h) {
		swap(*this, h);
		return *this;
	}
private:
	string *ps;
	int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.i, rhs.i);
	swap(lhs.ps, rhs.ps);
}

int main()
{
	HasPtr p1, p2;
	p1 = std::move(p2);		// 二义性调用	
	return 0;
}