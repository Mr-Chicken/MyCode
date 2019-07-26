class HasPtr {
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	~HasPtr() {delete ps;}
	HasPtr(const HasPtr &hp) {
		i = hp.i;
		ps = new string(*hp.ps);
	}
	HasPtr& operator=(const HasPtr &hp) {
		auto newp = new string(*hp.ps);
		i = hp.i;
		delete ps;
		ps = newp;
		return *this;
	}
private:
	string *ps;
	int i;
};