

#include<iostream>
#include<limits.h>
using namespace std;

void printIndex(int a[], int index, int n, int element)
{
    if(index>=n) return;

    // ek case solve kro
    if(a[index]==element) cout << index << " ";

    printIndex(a,index+1,n,element);
}

int main()
{
    int arr[] = {10,20,10,10,20,30,50,10};

    printIndex(arr,0,8,10);

    return 0;
}