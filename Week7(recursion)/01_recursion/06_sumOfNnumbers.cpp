
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
using namespace std;

int sumOfNnumbers(int n)
{
    // base case
    if(n==1) return 1;

    int sum = n+sumOfNnumbers(n-1);

    return sum;
}

int main()
{

    cout << sumOfNnumbers(9);

    return 0;
}