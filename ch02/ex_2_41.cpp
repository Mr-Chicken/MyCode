#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
bool readSalesData(Sales_data *sd) { // use reference for the better
    cin >> sd->isbn;
    cin >> sd->units_sold;
    cin >> sd->revenue;
    return true;
}
int main() {
    Sales_data cur, var;
    cin >> cur.isbn;
    cin >> cur.units_sold;
    cin >> cur.revenue;
    if (cur.isbn != "") {
	int cnt = 1;
	unsigned totalPrice = cur.units_sold*cur.revenue;
	unsigned totalRevenue = 0;
	while (readSalesData(&var)) {
	    if (var.isbn == cur.isbn) {
		cnt++;
		totalPrice += var.units_sold*var.revenue;
		cur.units_sold += var.units_sold;
		cur.revenue += var.revenue;
		totalRevenue += cur.revenue;
	    } else {
		cout << cur.isbn << " " << cur.units_sold << " " << totalPrice << " " << totalRevenue/cnt << endl;
		cnt = 1;
		cur.isbn = var.isbn;
		cur.units_sold = var.units_sold;
		cur.revenue = var.revenue;
	    }
	}
    } else {
	cout << "No Sales!?" << endl;
    }
    return 0;
}
