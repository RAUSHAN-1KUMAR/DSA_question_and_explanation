/*
Question:- we have an rotated and sorted array. find the pivot element in the given array

The pivot element is the maximum element of that array.
*/

/*
Approach:- discribed in notecopy.
*/

#include<iostream>
#include<vector>

using namespace std;

int findPivotIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size()-1; 
    int n = arr.size();

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(start==end) return start;// catch condition

        if(arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid] < arr[start]) end = mid-1;
        else start = mid+1;
    }

    return -1;
}

int main()
{
    vector<int> v = {7,8,9,1,2,3,4,5,6};

    cout << findPivotIndex(v) << endl;

    return 0;
}