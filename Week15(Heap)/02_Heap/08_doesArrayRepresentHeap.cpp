/* -> 

Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

Example 1:
    Input:n = 6, arr[] = {90, 15, 10, 7, 12, 2}
    Output: 1
    Explanation: 
    The given array represents below tree
        90
      /    \
    15      10
    /  \     /
    7  12   2
    The tree follows max-heap property as every
    node is greater than all of its descendants.


Example 2:
    Input: n = 6, arr[] = {9, 15, 10, 7, 12, 11}
    Output: 0
    Explanation:
    The given array represents below tree
        9
      /   \
    15      10
    /  \     /
    7   12  11
    The tree doesn't follows max-heap property 9 is
    smaller than 15 and 10, and 10 is smaller than 11. 

*/

/*
Approach:-
    -- iterate through each element, and if at any element the maxHeap condition is not satisfied than we will return false.
*/

#include<bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    if(n<=1) return true;
    
    bool ans = true;
    
    int leafNodeStartingIndex = n/2;
    int index = 0;
    
    while(index<leafNodeStartingIndex)
    {
        int leftChild = (index*2)+1;
        int rightChild = (index*2)+2;
        
        if(leftChild<n && arr[index]<arr[leftChild])
            return false;
        
        if(rightChild<n && arr[index]<arr[rightChild])
            return false;
        
        index++;
    }
    
    return ans;
}

int main()
{
    int arr[] = {9,15,10,7,12,11};
    int n = 6;

    cout << isMaxHeap(arr, n) << endl;

    return 0;
}