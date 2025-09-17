/*
Debug the code. Convert Binary to Decimal.
*/

#include<iostream>
using namespace std;

int main() {
    int n,sum=0,factor=1;
    cin>>n;

    while(n!=0){
        int digit = n/10;
        sum = sum + digit*factor;
        factor = 2*factor;
        n = n%10;
    }
    
    cout<<sum;
    return 0;
}

/* Correct code
int main() 
{
    int n,sum=0,factor=1;
    cout << "Enter in binary code: ";
    cin>>n;

    while(n!=0){
        int digit = n%10;
        sum = sum + digit*factor;
        factor = 2*factor;
        n = n/10;
    }

    cout << "The decimal equivalent of your given binary code is: ";
    cout<<sum<< endl;
    return 0;
}
*/