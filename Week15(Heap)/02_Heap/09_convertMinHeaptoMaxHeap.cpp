/* GFG

You are given an array arr of N integers representing a min Heap. The task is to convert it to max Heap.

A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. 

Example 1:
    Input:
    N = 4
    arr = [1, 2, 3, 4]
    Output:
    [4, 2, 3, 1]

*/

/*
Approach:
    -- logic will be similar to array to maxHeap
*/

#include<bits/stdc++.h>
using namespace std;

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for(int i=N/2-1 ; i>=0 ; i--)
    {
        int index=i;
        while(index<N)
        {
            int lc = index*2 + 1;
            int rc = index*2 + 2;
            int li = index;

            if(lc < N && arr[lc]>arr[li])
                li = lc;

            if(rc < N && arr[rc]>arr[li])
                li = rc;

            if(li==index) break;
            else {
                swap(arr[index], arr[li]);
                index = li;
            }
        }
    }
}

int main()
{
    vector<int> arr = {3,4,8,11,13};
    convertMinToMaxHeap(arr, arr.size());
    for(int num:arr)    
        cout << num <<  " ";
    cout << endl;
    return 0;
}