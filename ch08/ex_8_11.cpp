#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::ostream;
using std::istringstream;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

struct PersonInfo {
    string name;
    std::vector<string> phones;
};

int main() {
    string line, word;
    std::vector<PersonInfo> people;
    istringstream iss;
    while (std::getline(std::cin, line)) {
        PersonInfo info;
        iss.str(line);
        iss >> info.name;
        while (iss >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    return 0;
}
