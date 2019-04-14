#include <iostream>
using namespace std;

int main()
{
	int grade;

	//version 2 for the better
	while (cin >> grade) {
		if (grade >= 90)
			cout << "high pass" << endl;
		else if (grade >=75 && grade < 90)
			cout << "pass" << endl;
		else if (grade >=60 && grade < 75)
			cout << "low pass" << endl;
		else 
			cout << "fail" << endl;
	}
	
	return 0;
}