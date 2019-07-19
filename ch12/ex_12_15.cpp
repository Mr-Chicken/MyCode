#include <iostream>
#include <memory>

using std::shared_ptr;

struct destination {};
struct connection {};
connection connect(destination *dest) {}
void disconnect(connection *con) {}
void f(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> ptr(&c, [](connection *p) {
		disconnect(p);
	});
}

int main()
{
	destination dest;
	f(dest);
	return 0;
}