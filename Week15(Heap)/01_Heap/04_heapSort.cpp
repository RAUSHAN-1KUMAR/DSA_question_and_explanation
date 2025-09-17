/*
Given an array: {5,10,15,20,25,12}

Sort it using heap
*/

/*
Approach: 
    -- sabse pehle array ko max heap m convert ker rhe h uske baad
    -- aage se element nikalo aur last se swap krdo, element ko swap ker rhe h but we treat hoga deletion ke jaise i.e., swap hone ke baad size of heap decrease hoga
    -- swap kerne ke baad, jo element front m aya, ab uspe heapify lagado

TC-> O(nlogn)
*/


#include<bits/stdc++.h>
using namespace std;

void printHeap(int arr[], int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// indexing from 1 ke liye(heapify goes from top to down)
void heapify(int *arr, int n, int index)
{
    int leftChild = 2*index;
    int rightChild = 2*index+1;
    int largestIndex = index;

    if(leftChild<=n && arr[leftChild]>arr[largestIndex])
        largestIndex = leftChild;

    if(rightChild<=n && arr[rightChild]>arr[largestIndex])
        largestIndex = rightChild;


    if(index!=largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

// bottom-up approach
void buildHeap(int arr[], int n)
{
    for(int index=n/2 ; index>=1; index--)
    {
        heapify(arr, n, index);
    }
}

// indexing 1 ke liye (top-down approach)
void heapSort(int arr[], int n)
{
    while(n>1)
    {
        swap(arr[1], arr[n]);
        
        n--;

        heapify(arr,n,1);
    }
}

int main()
{
    int arr[] = {-1,5,10,15,20,25,12};
    printHeap(arr, 6);

    cout << "first converted into max heap: " << endl;
    buildHeap(arr,6); //-> O(n)
    printHeap(arr, 6);

    cout << "Using heap sort: " << endl;
    heapSort(arr, 6); //-> O(nlogn)
    
    cout << "After sorting: " << endl;
    printHeap(arr, 6);

    return 0;
}