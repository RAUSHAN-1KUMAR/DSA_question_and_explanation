
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/

#include<iostream>
using namespace std;

int fact(int n) 
{
    // base case
    if(n==1 || n==0) return 1;

    // processing(ek case solve kro)
    int finalAns = n * fact(n-1);

    return finalAns;
}


int main()
{
    cout << fact(5) << endl;
    return 0;
}