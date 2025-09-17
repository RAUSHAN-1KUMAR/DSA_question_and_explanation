/*
To check given number is prime or not
*/

#include<iostream>
using namespace std;

bool checkPrime(int n)
{
    int i = 2;
    for(i = 2 ; i<n ; i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool isPrime = checkPrime(n);
    if(isPrime){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not prime" << endl;
    }

    return 0;
}