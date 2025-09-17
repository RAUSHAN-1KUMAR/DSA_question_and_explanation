/*
Given an array: {5,10,15,20,25,12}

Convert it into max heap array
*/

/*
Appraoch: 0th indexing ke liye

TC-> O(n), not O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

void printHeap(int arr[], int n)
{
    for(int i=0 ; i<=n-1 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// indexing from 0 ke liye
void heapify(int *arr, int n, int index)
{
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    
    int largestIndex = index;

   
    if(leftChild<=n && arr[leftChild]>arr[largestIndex])
        largestIndex = leftChild;

    //Change4
    if(rightChild<=n && arr[rightChild]>arr[largestIndex])
        largestIndex = rightChild;


    if(index!=largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

// bottom-up approach
void buildHeap(int arr[], int size)
{
    //size/2-1, because in case of 0 index the leaf nodes starts from size/2 to last index
    for(int index=size/2-1 ; index>=0; index--)
    {
        heapify(arr, size, index);
    }
}

int main()
{
    int arr[] = {5,10,15,20,25,12,60};
    printHeap(arr, 7);

    cout << "Converting into heap array: " << endl;
    buildHeap(arr, 7);

    cout << "After convertion: " << endl;
    printHeap(arr, 7);

    return 0;
}