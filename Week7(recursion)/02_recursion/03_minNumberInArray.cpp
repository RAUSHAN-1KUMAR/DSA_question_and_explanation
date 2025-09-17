
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
#include<limits.h>
using namespace std;

int minimumNumber(int a[], int index, int n, int intMax)
{
    // base case
    if(index>=n) return intMax;

    // processing(ek case solve kro)
    if(a[index]<intMax) intMax=a[index];

    // recursive call(baki recursion p chod do)
    int aageKaAns = minimumNumber(a, index+1, n, intMax);

    return aageKaAns;
}

int main()
{
    int arr[] = {7,20,30,40,5};

    cout << "The minimum number in an array: " << minimumNumber(arr,0,5,INT_MAX) << endl;

    return 0;
}