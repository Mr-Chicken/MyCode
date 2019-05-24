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
    std::ofstream out(argv[2], std::ofstream::app);

    if (read(in, total)) {
        Sales_data trans;
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                total.writeDown(out);
                total = trans;
            }
        }
        total.writeDown(out);
    } else {
        cout << "No data!?" << endl;
    }
    in.close();
    return 0;
}
