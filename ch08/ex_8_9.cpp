#include <iostream>
#include <sstream>

std::istream& read(std::istream &is){
    std::string s;
    while(std::getline(is, s))
        std::cout << s << std::endl;
    is.clear();
    return is;
}

int main() {
    std::string data("Hello World");
    std::istringstream iss(data);
    read(iss);
    return 0;
}
