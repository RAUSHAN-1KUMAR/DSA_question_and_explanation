/*
To find simple interest
*/

#include<iostream>
using namespace std;

int main()
{
    int p,t,r;
    float SI;

    cout << "Enter the principle amount: " ;
    cin >> p;

    cout << "Enter the time in years:  ";
    cin >> t;

    cout << "Enter the rate of interest: ";
    cin >> r;
 
    SI = float(p*r*t)/100;

    cout << "The simple interest will be: " << SI;

    return 0;
}