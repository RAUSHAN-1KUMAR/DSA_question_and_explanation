
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
#include<limits.h>
using namespace std;

int minimumNumber(int a[], int index, int n)
{
    // base case
    if(index == n-1){
        return a[index];
    }

    return min(a[index], minimumNumber(a,index+1,n));
}

int main()
{
    int arr[] = {7,20,30,40,5};

    cout << "The minimum number in an array: " << minimumNumber(arr,0,5) << endl;

    return 0;
}