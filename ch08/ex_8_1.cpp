#include <iostream>
using std::istream;
using std::cout;
using std::cin;
using std::endl;
istream& func(istream &is) {
    std::string s;
    while(cin >> s)
        cout << s <<endl;
    is.clear();
    return is;
}

int main() {
    func(cin);
    cout << cin.rdstate() << endl;
}
