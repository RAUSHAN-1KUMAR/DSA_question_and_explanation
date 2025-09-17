/*
To check given number is prime or not
*/

#include<iostream>
#include<math.h>
using namespace std;

bool checkPrime(int n)
{
    int i = 2;
    for(i = 2 ; i<=(sqrt(n)) ; i++) // replaced n as sqrt(n), this is the optimized solution
    { // but but but the answer is wrong for input n = 4;
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