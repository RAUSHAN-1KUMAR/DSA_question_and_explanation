
/*
We have given an array, and we have to check it is sorted or not
*/

#include<iostream>
using namespace std;

bool checkSorted(int a[], int index, int n)
{

    if(index==n-1) return true;

    if(a[index]>a[index+1]) return false;

    return checkSorted(a,index+1,n);
}

int main()
{
    int arr[] = {10,20,30,4,50};

    if(checkSorted(arr,0,5)) cout << "Sorted";
    else cout << "Unsorted";

    return 0;
}