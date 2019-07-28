#ifndef STRING_H
#define STRING_H
#include <memory>
#include <utility>
using std::allocator;
class String {
public:
	String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char *str);
	String(const String &s);
	~String();
	String& operator=(const String &s);
	char* begin() const {return elements;}
	char* end() const {return first_free;}
	size_t size() {return first_free - elements;}
	size_t capacity() {return cap - elements;}
private:
	allocator<char> alloc;
	std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
	void free();		// 销毁元素并释放内存
	void reallocate();	// 获得更多内存并拷贝已有内存
	char *elements;		// 该数组首元素
	char *first_free;	// 该数组第一个空闲位置
	char *cap;			// 该数组尾后指针
};

#endif