

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int sumOfDigits(int num)
{
    // base case
    if(num==0) return 0;

    return (num%10) + sumOfDigits(num/10); 
}

int main()
{
    int number = 456;

    cout << sumOfDigits(number) << endl;

    return 0;
}