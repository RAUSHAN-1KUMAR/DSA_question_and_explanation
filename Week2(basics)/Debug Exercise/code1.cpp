/*
code is trying to calculate area of a rectangle.
*/

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

int main() 
{
	double width, height;
	cin >> width >> height;
	int area = width * height;
	cout << area << endl;
	return 0;
}

/* Correct code
int main() 
{
	double width, height;
	cin >> width >> height;

	double area =  (width * height)/2;

	cout << area << endl;

	return 0;
}
*/
