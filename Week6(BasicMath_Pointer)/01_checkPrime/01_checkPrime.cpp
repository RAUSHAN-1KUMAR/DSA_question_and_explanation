/*
Naive appraoch:- The naive approach to check for a prime number is by checking divisibility from 2 to n-1. If n is divisible by any number in this range, it's not prime.
*/

#include<iostream>
using namespace std;

bool isPrime(int n) 
{
    // 0 and 1 are not prime numbers
    if (n <= 1) return false; 
    
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0) {
            return false; // If n is divisible by any number other than 1 and itself, it is not prime
        }
    }
    
    return true;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isPrime(num)) cout << "Prime";
    else cout << "Not Prime";

    return 0;
}