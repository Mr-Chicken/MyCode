#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::cin;

struct Person {
	std::string name;
	std::string address;

	const std::string& getName() const { return name; };
	const std::string& getAddress() const { return address; };
};

ostream& print(ostream &out, const Person &p) {
	out << "Name: " << p.getName() << endl;
	out << "Address: " << p.getAddress() << endl;
	return out;
}

istream& read(istream &in, Person &p) {
	in >> p.name >> p.address;
	return in;
}
