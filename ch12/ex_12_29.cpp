#include "ex_12_27.h"
void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    do { // 我感觉都差不多，至少改例子体现不出来。
        cout << "enter word to look or, q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    } while (true);
}