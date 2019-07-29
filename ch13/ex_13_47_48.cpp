#include <iostream>
#include <vector>

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

void String::free() {
	if (elements) {
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
String::~String() {
	free();
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
	auto newData = alloc.allocate(e - b);
	return {newData, std::uninitialized_copy(b, e, newData)};
}

void String::reallocate() {
	auto newCapacity = size() ? size() * 2 : 1;
	auto newData = alloc.allocate(newCapacity);
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}
String::String(const String &s) {
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

String& String::operator=(const String &s) {
	auto newData = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	std::cout << "String::operator=(const String &s)" << std::endl;
	return *this;
}

String::String(const char *str) {
	char *s = const_cast<char*>(str);
	while (*s)
		++s;
	auto newData = alloc_n_copy(str, ++s);
	elements = newData.first;
	first_free = cap = newData.second;

	std::cout << "String(const char *str)" << std::endl;
}

int main()
{
	std::vector<String> vec;
	vec.push_back(String("A"));
	vec.push_back(String("B"));
	vec.push_back(String("C"));	
	// 3 times
	return 0;
}