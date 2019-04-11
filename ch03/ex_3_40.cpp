#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	char str1[] = "123";
	char str2[] = "456";

	char arr[20];
	strcpy(arr,str1);
	strcat(arr,str2);

	cout << arr << endl;
	return 0;
}