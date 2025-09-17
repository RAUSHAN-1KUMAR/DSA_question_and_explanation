/*

Given an integer array nums. Return the number of inversions in the array.

Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
    - It indicates how close an array is to being sorted.
    - A sorted array has an inversion count of 0.
    - An array sorted in descending order has maximum inversion.

Examples:
    Input: nums = [2, 3, 7, 1, 3, 5]
    Output: 5
    Explanation: The responsible indexes are:
        nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
        nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
        nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
        nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
        nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

    Input: nums = [-10, -5, 6, 11, 15, 17]
    Output: 0
    Explanation: nums is sorted, hence no inversions present.
*/

/*
Approach: 
    -- a solution would be useful if use one of the sorting algorithm and count the inversions
    -- lets use merge sort for better TC:- O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    
    int i=low;
    int j=mid+1;

    int cnt=0;

    while (i<=mid && j<=high)
    {
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            cnt+=(mid-i+1);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    // transfering all elements from temporary to arr
    for(int i=low; i<=high ; i++){
        arr[i]=temp[i-low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt=0;
    
    if(low>=high) return cnt;

    int mid = (low + high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);

    cnt+=merge(arr, low, mid, high);

    return cnt;

}

int numberOfInversions(vector<int> &a, int &n)
{
    return mergeSort(a, 0, n-1);
}

int main()
{
    vector<int> a = {2,3,7,1,3,5};
    int n=a.size();
    int cnt=numberOfInversions(a, n);
    cout << cnt << endl;
    return 0;
}
