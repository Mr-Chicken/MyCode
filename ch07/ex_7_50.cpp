class Person {
friend std::istream& read(std::istream &, Person &);
friend std::ostream& print(std::ostream &, const Person &);
private:
    std::string name;
    std::string address;
public:
    Person() = default;
    Person(const std::string &n, const std::string &add): name(n), address(add) {}
    explicit Person(std::istream &is) { read(std::cin, *this);}
    const std::string& getName() const {return name;}
    const std::string& getAddress() const {return address;}
};
