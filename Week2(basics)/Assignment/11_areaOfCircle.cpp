/*
To print area of a circle
*/

#include<iostream>
using namespace std;

float circleArea(float r)
{
    float area = 3.14 * r * r;
    return area;
}


int main()
{
    float radius;
    cout << "Enter the radius of circle: ";
    cin >> radius;

    cout << "The area of the circle is: " << circleArea(radius) << endl;
    
    return 0;
}