/*
Given an array: {5,10,15,20,25,12}

Convert it into max heap array
*/


/*
Appraoch: bottom-up i.e., array ke last se, except leaf nodes
    --catch, array ke case m to indexing 0 se hota hai
        1. to ham kya krengen ki 0th index p koi aur value rakh ker 1th index se array element ko rakhenge
            ex: arr = {-1,5,10,15,20,25,12}

        2. ya phir ham direct 0th indexing ke liye bhi logic bna ke solve ker sakte h -> see next solution

TC-> O(nlogi) approx = O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void printHeap(int arr[], int n)
{
    for(int i=1 ; i<=n-1 ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// indexing from 1 ke liye
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

// bottom-to-up building i.e, from last of the array
void buildHeap(int arr[], int size)
{
    int n = size-1; // because n, which is basically the size of the array element is out of bound.

    // n/2 se issliye, because in case of one base indexing array the element from n/2+1 to last index are basically leaf nodes so no need to heapify them because heapify function need that node whose child exits. -> if indexing from 1
    for(int index=n/2 ; index>=1; index--)//-> O(n)
    {
        heapify(arr, n, index); //-> logi
    }
}


int main()
{
    int arr[] = {-1,5,10,15,20,25,12,60};
    printHeap(arr, 8);

    cout << "Converting into heap array: " << endl;
    buildHeap(arr, 8);

    cout << "After convertion: " << endl;
    printHeap(arr, 8);

    return 0;
}


