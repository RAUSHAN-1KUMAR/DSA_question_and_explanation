
/*
Ek case solve kero baki case ka recursion answer lake dega + handle the base case
*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void doubleElements(int arr[],int index, int n)
{
    if(index>=n) return;

    // ek case solve kro
    arr[index] *= 2;

    doubleElements(arr, index+1, n);
}

int main()
{
    int a[] = {10,11,12,13,14};

    doubleElements(a,0,5);

    for(auto ele:a){
        cout << ele << endl;
    }

    return 0;
}