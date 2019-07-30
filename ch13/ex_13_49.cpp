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
	StrVec(StrVec &&s) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec &&s) noexcept;
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

// StrVec
StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
	s.elements = s.first_free = s.cap = nullptr;	// 进入可析构状态
}

StrVec& StrVec::operator=(StrVec &&s) noexcept {
	if (this != &s) {
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

#include <memory>
#include <utility>
using std::allocator;
class String {
public:
	String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char *str);
	String(const String &s);
	String(String &&s) noexcept;
	~String();
	String& operator=(const String &s);
	String& operator=(String && rhs) noexcept;
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
// String
String::String(String &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String && rhs) noexcept {
	if (this != &rhs) {
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

#include <string>
#include <set>
using std::set
using std::string;

class Folder;
class Message {
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string &str = string()):contents(str) {}
	Message(const Message&);
	Message(Message &&m) noexcept;
	Message& operator=(const Message&);
	Message& operator=(Message &&rhs) noexcept;
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;		// 消息文本
	set<Folder*> folders;	// 包含本Message的Folder
	void add_to_Folders(const Folder &f);
	void remove_from_Folders();
	void move_Folders(Message *m);
};

void Message::move_Folders(Message *m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}
void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove() {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
	for (auto f : folders)
		f->addMsg(this);
}
Message::Message(const Message &m): contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}
void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
}
Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message &m) {
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}
void swap(Message &lhs, Message &rhs) {
	using std::swap;
	for (auto f :lhs.folders)
		f->remMsg(&lhs);
	for (auto f :rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f :lhs.folders)
		f->addMsg(&lhs);
	for (auto f :rhs.folders)
		f->addMsg(&rhs);
}
// Message

Message::Message(Message &&m) noexcept :contents(std::move(m.contents)){
	move_Folders(&m);
}
Message& Message::operator=(Message &&rhs) noexcept {
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}