/*
To find factorial of a given number
    (we will use long long int, why?)
*/

#include<iostream>
using namespace std;

long long int factorial(long long int n)
{
    long long int fact = 1;
    for(int i = 1 ; i<=n ; i++)
    {
        fact =  fact*i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long int ans = factorial(n);
    cout << "The factorial of given number " << n << "is " << ans << endl;
    return 0;
}