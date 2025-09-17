/*
To print all the prime number upto input n.
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


    if(n<2) cout << "The lowest prime number is: 2" << endl << "So enter value greater than or equal to 2";
    else{
        for(int i = 2 ; i<=n ; i++)
        {
            bool isPrime = checkPrime(i);
            if(isPrime){
                cout << i << " ";
            }
        }
    }

    return 0;
}