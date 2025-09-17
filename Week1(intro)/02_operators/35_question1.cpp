/*
finding roots of a quadratic equation
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float a,b,c,r1,r2;
    cout << "Write the value of a,b and c of the quadratic equation ax^2 + bx + c having discriminant greater than or equal to 0: ";
    cin >> a >> b >> c;

    r1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    r2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

    cout << "The roots are: " << r1 << " and " << r2 ;

    return 0;
}