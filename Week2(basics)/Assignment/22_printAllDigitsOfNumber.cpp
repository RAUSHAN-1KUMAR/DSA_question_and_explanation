/*
Print all digits of an integers
*/

#include<iostream>
using namespace std;

void printDigits(int n)
{
    if(n>1) printDigits(n/10);
    cout << n%10 << endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printDigits(n);

    return 0;
}