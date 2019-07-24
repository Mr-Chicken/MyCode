#include "ex_12_30.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(cout, tq.query(s)) <<endl;
    }
}

int main() {
    std::ifstream infile("infile");
    runQueries(infile);
    return 0;
}