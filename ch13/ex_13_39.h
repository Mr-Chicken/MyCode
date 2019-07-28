#ifndef EX_13_39_H
#define EX_13_39_H
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>
using std::string;
using std::initializer_list;

class StrVec {
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const initializer_list<string> &init);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	string* begin() const {return elements;}
	string* end() const {return first_free;}
	void reverse(size_t n);
	void resize(size_t n);
	void resize(size_t n, const string &s);
private:
	std::allocator<string> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate();}
	std::pair<string*, string*> alloc_n_copy(const string *, const string *);
	void free();		// 销毁元素，释放内存
	void reallocate();	// 申请更多内存并拷贝已有元素
	string *elements;	// 指向数组首元素指针
	string *first_free;	// 指向数组最后以一个空闲元素指针
	string *cap;		// 指向数组尾后位置指针
};

#endif