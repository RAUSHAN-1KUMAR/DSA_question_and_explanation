/* very important function in heap Data Structure

heapify function:- 
    - This function is particularly useful when you need to turn an array into a valid heap or restore the heap property after an insertion or deletion

    - The heapify function typically works by comparing the root node with its children and swapping it with the largest (for a max-heap) or smallest (for a min-heap) child if the root does not satisfy the heap property.

IMP - we can apply this heapify function on index i only if all elements in both left and right subtrees are following heap property, i.e., left and right subtrees of index i are already a heap

TC-> O(logn)
*/

/*
Approach:- using recursion
    -- this heapify function basically build to maintain the property of heap, from a perticular index.
    -- this heapify function will go from top-to-down
*/

#include<bits/stdc++.h>
using namespace std;

// max heap: for indexing 1
void heapify(int *arr, int n, int index)
{
    int leftChild = 2*index;
    int rightChild = 2*index+1;
    
    int largestIndex = index;

    // teeno me se max lao, just like we did in case of deletion
    if(leftChild<=n && arr[leftChild]>arr[largestIndex])
        largestIndex = leftChild;

    if(rightChild<=n && arr[rightChild]>arr[largestIndex])
        largestIndex = rightChild;

    // change in index
    if(index!=largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

// max-heap: for indexing 0
void heapify(int *arr, int n, int index)
{
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;

    int largestIndex = index;

    // teeno me se max lao, just like we did in case of deletion
    if(leftChild<=n && arr[leftChild]>arr[largestIndex])
        largestIndex = leftChild;

    if(rightChild<=n && arr[rightChild]>arr[largestIndex])
        largestIndex = rightChild;

    // change in index
    if(index!=largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

int main()
{

    return 0;
}