/*
sum of first n natural number
*/

#include<iostream>
using namespace std;

int main()
{
    int n,sum;
    cout << "Enter a number: ";
    cin >> n;

    sum = n*(n+1)/2 ;

    cout << "The sum of first " << n << " natural number is: " << sum ;
    return 0;
}

