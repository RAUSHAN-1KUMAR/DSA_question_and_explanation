
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
using namespace std;

void printArray(int a[], int n)
{
    // base case
    if(n==0) return;

    // process(ek case solve kro)
    cout << *a << " ";

    printArray(a+1, n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};

    printArray(arr,5);

    return 0;
}