#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;
using std::showbase;
using std::hex;
using std::showbase;
using std::uppercase;
using std::scientific;
using std::showpoint;
using std::oct;
using std::dec;
using std::fixed;
using std::left;
using std::right;
using std::internal;
using std::setw;
using std::setfill;
using std::noshowpoint;
int main()
{
	cout << "boolalpha: " << boolalpha << true << " " << false << noboolalpha << endl;
	cout << showbase << uppercase << hex << 0x16 << 
	 " " << oct << 20 << 
	 " " << dec << 10 << endl;
	cout << "show point: " << showpoint << 10.0 << endl;
	cout << "scientific: " << scientific << sqrt(26.7) << endl << fixed << noshowpoint;

	int i = -16;
	double d = 3.14159;

	cout << "i: " << setw(12) << i << "next col" << '\n'
		 << "d: " << setw(12) << d << "next col" << '\n';
	cout << left << "i: " << setw(12) << i << "next col" << '\n'
		 << "d: " << setw(12) << d << "next col" << '\n';
	cout << right << "i: " << setw(12) << i << "next col" << '\n'
		 << "d: " << setw(12) << d << "next col" << '\n';
	cout << internal << "i: " << setw(12) << i << "next col" << '\n'
		 << "d: " << setw(12) << d << "next col" << '\n';
	cout << setfill('#') << "i: " << setw(12) << i << "next col" << '\n'
		 << "d: " << setw(12) << d << "next col" << '\n' << setfill(' ');
	return 0;
}