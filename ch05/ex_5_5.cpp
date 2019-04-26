#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	const std::vector<string> v {"F","D","C","B","A","A++"};

	string letterGrade;
	int grade;
	cin >> grade;
	if (grade < 60)
		letterGrade = v[0]; // failed
	else {
		letterGrade = v[(grade-50)/10];
	}
	cout << "Grade: " << letterGrade << endl;
	return 0;
}