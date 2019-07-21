#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

int main() {
	char *buf = new char[strlen("helloworld") + 1];
	strcat(buf, "hello");
	strcat(buf, "world");
	cout << buf << endl;
	delete []buf;

	string sbuf;
	sbuf += "world";
	sbuf += "hello";
	cout << sbuf << endl;
	return 0;
}