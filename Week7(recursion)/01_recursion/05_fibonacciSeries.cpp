
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
using namespace std;

int fibonacci(int n)
{
    // base base
    if(n==1) return 1;
    if(n==0) return 0;

    // head recursion
    int finalAns = fibonacci(n-1) + fibonacci(n-2);

    return finalAns;
}


int main()
{
    cout << fibonacci(2) << endl;

    return 0;
}