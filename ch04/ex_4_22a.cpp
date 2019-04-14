#include <iostream>
using namespace std;

int main()
{
	int grade;

	//version 1
	while (cin >> grade) {
		cout << ((grade>=90)? "high pass":
			(grade<90 && grade >=75)? "pass":(grade>=60 && grade <75)? "low pass":"fail")
				<< endl;
	}
	
	return 0;
}