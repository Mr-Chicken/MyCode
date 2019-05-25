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

int main(int argc, char *argv[]) {
    string line, word;
    std::vector<PersonInfo> people;
    ifstream is(argv[1]);
    while (std::getline(is, line)) {
        PersonInfo info;
        istringstream iss(line);
        iss >> info.name;
        while (iss >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for (const auto &s : people) {
        cout << s.name << " ";
        for (const auto &p : s.phones)
            cout << p;
        cout << endl;
    }
    is.close();
    return 0;
}
