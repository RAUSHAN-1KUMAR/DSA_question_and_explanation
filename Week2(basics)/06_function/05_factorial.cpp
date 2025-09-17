#include<iostream>
using namespace std;

int fact(int n)
{
    int fact = 1;
    for(int i = 1 ; i<=n ; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "The factorial of your given number " << n << " is " << fact(n);
    
    return 0;
}