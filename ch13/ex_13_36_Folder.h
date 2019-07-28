#ifndef EX_13_36FOLDER_H
#define EX_13_36FOLDER_H
#include <string>
#include <set>
using std::set;
using std::string;

class Folder;
class Message {
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const string &str = string()):contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder *f) {folders.insert(f);}
	void remFldr(Folder *f) {folders.erase(f);}
private:
	string contents;		// 消息文本
	set<Folder*> folders;	// 包含本Message的Folder
	void add_to_Folders(const Folder &f);
	void remove_from_Folders();
};

class Folder {
	friend class Message;
	friend void swap(Folder &f1, Folder &f2);
public:
	Folder() = default;
	Folder(const Folder &);
	~Folder();
	Folder& operator=(const Folder&);
private:
	set<Message*> messages;
	void add_to_Messages(const Folder &);
	void remove_from_Messages();
	void addMsg(Message*);
	void remMsg(Message*);
};

#endif 