class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	StrBlob(const StrBlob &rhs): data(make_shared(*rhs.data)) {}
	StrBlob& operator=(const StrBlob &rhs) {
		data.reset(new vector<string>(*rhs.data));
	}
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const string &s) {data->push_back(s);}
	void pop_back();
	StrBlobPtr begin();
	StrBlobPtr end();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) {}
	
	StrBlobPtr(StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref();
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	size_t curr;
};