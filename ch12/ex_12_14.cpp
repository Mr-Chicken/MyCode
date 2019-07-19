#include <iostream>
#include <memory>

using std::shared_ptr;

struct destination {};
struct connection {};
connection connect(destination *dest) { return connection();}
void disconnect(connection *con) {}
void end_connection(connection *p) {
	disconnect(p);
}

void f(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> ptr(&c, end_connection);
}

int main()
{
	destination dest;
	f(dest);
	return 0;
}