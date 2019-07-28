#include "ex_13_36_Folder.h"

void Folder::add_to_Messages(const Folder &f) {
	for (auto x : f.messages)
		x->addFldr(this);
}
void Folder::remove_from_Messages() {
	for (auto x : messages)
		x->remFldr(this);
}

Folder::~Folder() {
	remove_from_Messages();
}

void Folder::addMsg(Message *m) {
	messages.insert(m);
}

void Folder::remMsg(Message *m) {
	messages.erase(m);
}

Folder::Folder(const Folder &f):messages(f.messages){
	add_to_Messages(f);
}
Folder& Folder::operator=(const Folder &f) {
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

void swap(Folder &f1, Folder &f2) {
	using std::swap;
	for (auto m : f1.messages) 
		m->remFldr(&f1);
	for (auto m : f2.messages)
		m->remFldr(&f2);

	swap(f1.messages, f2.messages);

	for (auto m : f1.messages)
		m->addFldr(&f1);
	for (auto m : f2.messages)
		m->addFldr(&f2);
}