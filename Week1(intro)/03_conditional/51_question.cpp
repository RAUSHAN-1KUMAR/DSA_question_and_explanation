
// nature of roots of a quadratic equation.

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float a,b,c,d,r1,r2;
    cout << "enter a b and c: ";
    cin >> a >> b >> c;

    d = b*b - 4*a*c;

    if(d == 0){
        cout << "roots are real and equal: ";
        cout << (-b/(2*a));
    }
    else if(d > 0){
        cout << "roots are real and distinct: ";
        cout << (-b + sqrt(d))/(2*a) << " " << (-b - sqrt(d))/(2*a);
    }
    else{
        cout << "roots are imaginary";
    }
    
    return 0;
}
