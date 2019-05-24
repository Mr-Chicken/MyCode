#include <iostream>
#include <fstream>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::string;
using std::istream;

int main(int argc, char *argv[]) {
    Sales_data total;
    std::ifstream in(argv[1]);
    if (read(in, total)) {
        Sales_data trans;
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    } else {
        cout << "No data!?" << endl;
    }
    in.close();
    return 0;
}
