/*
To check given number is prime or not
*/

#include<iostream>
using namespace std;

int prime  = 1;

void checkPrime(int n)
{
    for(int i = 2 ; i<n ; i++)
    {
        if(n%i==0)
        {
            prime = 0;
            break;
        }
    }
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(num<2) cout << "The lowest prime number is 2." << endl;
    else{
        checkPrime(num);

        if(prime == 1) cout << "prime" << endl;
        else cout << "Not prime" << endl;
    }

    return 0;
}