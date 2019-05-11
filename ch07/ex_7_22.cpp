#include <iostream>

class Person {
friend std::istream& read(std::istream &, Person &);
friend std::ostream& print(std::ostream &, const Person &);
private:
    std::string name;
    std::string address;
public:
    Person() = default;
    Person(const std::string &n, const std::string &add): name(n), address(add) {}
    Person(std::istream &is) { read(std::cin, *this);}
    const std::string& getName() const {return name;}
    const std::string& getAddress() const {return address;}
};

std::istream& read(std::istream &is, Person &s) {
    is >> s.name >> s.address;
    return is;
}

std::ostream& print(std::ostream &os, const Person &s) {
    os << s.getName() << " " << s.getAddress() << std::endl;
    return os;
}
