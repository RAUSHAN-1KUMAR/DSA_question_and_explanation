/*
Given an array, find the kth smallest element in it
*/

/*
Appraoch:- PIVOT method 
    -- we can use the same code in case if it says to find the kth largest element, How?? -> we will find the (n-k)th smallest element, and that would be kth largest element

AVG:- O(n), Worst:- O(n^2)
Spcae:- O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];// lets take left most element as pivot element
    
    // now we will place it in his correct position between (left+1) to right
    int l = left+1;
    int r = right;

    while(l<=r)
    {
        if(arr[l]>pivot && arr[r]<pivot)
        {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }

        if(arr[l]<=pivot)
            l++;

        if(arr[r]>=pivot)
            r--;
    }
    
    // place the pivot at its correct position(r)
    swap(arr[left], arr[r]);

    // return pivot index(r)
    return r;
}

int kthSmallestElement(vector<int> &arr, int k)
{
    // this is start and end
    int start = 0;
    int end = arr.size()-1;

    int ans;

    // running a loop till i get my answer
    while (1)
    {
        // lets find the pivot index of pivot element, pivot element will be its correct position
        int index = partition(arr, start, end);

        // if pivot index matches the required k-1, means return the pivot element
        if(index==k-1)
        {
            ans = arr[index];
            break; 
        }
        else if(index < k-1) // if pivot index is less than k-1, means we seek for more than indexth smallest number,
        {
            start = index+1;
        }
        else // if pivot is greater than k-1, means we seek for less than indexth smallest number
        {
            end = index-1;
        }
    }

    return ans;
}


int main()
{
    vector<int> arr = {7,10,4,3,20,15};
    int k = 3;

    cout << kthSmallestElement(arr, k) << endl;

    return 0;
}


