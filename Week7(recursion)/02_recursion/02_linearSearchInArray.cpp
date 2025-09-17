
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
using namespace std;

int linearSearch(int a[], int index, int n,int element)
{
    // base case
    if(index==n) return -1;

    // process(ek case solve kro)
    if(a[index] == element) return index;

    // recursive call
    int aageKaAns = linearSearch(a, index+1, n, element);

    return aageKaAns;
}

int main()
{
    int arr[] = {10,20,30,40,50};

    cout << "Element found at index: " << linearSearch(arr,0,5,50) << endl;

    return 0;
}