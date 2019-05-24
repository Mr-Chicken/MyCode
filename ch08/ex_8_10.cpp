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
int main() {
    string buf;
    ifstream file("words");
    std::vector<string> v;
    while (std::getline(file, buf))
        v.push_back(buf);
    for (const auto &s : v) {
        istringstream iss(s);
        while (iss >> buf)
            cout << buf << endl;
    }
    return 0;
}
