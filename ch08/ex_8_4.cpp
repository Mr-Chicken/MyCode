#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;

void read(std::string fileName) {
    std::vector<std::string> v;
    std::ifstream in(fileName);
    std::string s;

    while (in) {
        std::getline(in, s);
        v.push_back(s);
    }
    for (const std::string s : v)
        cout << s << endl;
    cout << v.size() << endl;
    in.close();
}

int main() {
    read("data");
    return 0;
}
