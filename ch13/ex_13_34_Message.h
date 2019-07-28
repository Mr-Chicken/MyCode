#ifndef EX_13_34_MESSAGE_H
#define EX_13_34_MESSAGE_H
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
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	string contents;		// 消息文本
	set<Folder*> folders;	// 包含本Message的Folder
	void add_to_Folders(const Folder &f);
	void remove_from_Folders();
};

#endif
