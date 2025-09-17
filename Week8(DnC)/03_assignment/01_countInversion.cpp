/* GFG

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.


Examples: 
    Input: arr[] = {8, 4, 2, 1}
    Output: 6
    Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

    Input: arr[] = {1, 20, 6, 4, 5}
    Output: 5
    Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 
*/

/*
Approach:- DnC(just like merge sort)
    -- counting the inversion at the time of merging i.e., if(a[i]>a[j]) count += mid-i+1;
*/

#include<iostream>
#include<vector>
using namespace std;

long finalMerge(vector<int> &arr, vector<int>& temp, int s, int mid, int e)
{
    long c = 0;
    int i=s;
    int j=mid+1;

    int k=s;
    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{// arr[i] > arr[j] -> inversion wala case
            temp[k] = arr[j];
            k++;
            j++;
            c += mid-i+1;
        }
    }

    while(i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j<=e)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }  

    while(s<=e)
    {
        arr[s] = temp[s];
        s++;
    }

    return c;
}


long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if(start>=end){
        return 0;
    }

    long c = 0;

    // breaking the array into two halves
    int mid = (start+end)/2;

    c += mergeSort(arr,temp,start,mid);

    c += mergeSort(arr,temp,mid+1,end); 

    c += finalMerge(arr,temp,start,mid,end);

    return c;
}


long countInversion(vector<int> &arr)
{
    // to store inversion counts
    long c = 0;

    vector<int> temp(arr.size(),0);

    c = mergeSort(arr, temp, 0, arr.size()-1);

    return c;
}


int main()
{
    vector<int> arr ={3,5,1,10,9,2,6,8};

    cout << countInversion(arr) << endl;

    return 0;
}