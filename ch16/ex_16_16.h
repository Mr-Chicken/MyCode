#ifndef EX_16_16_H
#define EX_16_16_H
#include <memory>
#include <initializer_list>
#include <utility>
using std::initializer_list;
template <typename T>
class Vec {
public:
	Vec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const initializer_list<T> &init);
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	~Vec();
	void push_back(const T&);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	T* begin() const {return elements;}
	T* end() const {return first_free;}
	void reverse(size_t n);
	void resize(size_t n);
	void resize(size_t n, const T &s);
private:
	std::allocator<T> alloc;
	void chk_n_alloc()
		{if (size() == capacity()) reallocate();}
	std::pair<T*, T*> alloc_n_copy(const T *, const T *);
	void free();		// 销毁元素，释放内存
	void reallocate();	// 申请更多内存并拷贝已有元素
	T *elements;	// 指向数组首元素指针
	T *first_free;	// 指向数组最后以一个空闲元素指针
	T *cap;		// 指向数组尾后位置指针
};
#endif