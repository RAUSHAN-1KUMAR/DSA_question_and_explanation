
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
using namespace std; 

int twoToPowerN(int n)
{
    // base case
    if(n==0){
        return 1;
    }

    // processing(ek case solve kro)
    int finalAns = 2 * twoToPowerN(n-1);

    return finalAns;
}


int main()
{
    cout << twoToPowerN(5) << endl;

    return 0;
}