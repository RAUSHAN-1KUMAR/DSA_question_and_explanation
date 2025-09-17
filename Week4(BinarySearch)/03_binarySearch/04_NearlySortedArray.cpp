/*
Now we have to apply binary search on nearly sorted array. 

So, what is the difference between sorted array and nearly sorted array?
    -- explained in notecopy

How to apply BS on nearly sorted array
    -- explained in notecopy

Example:-
    sorted:         10 20 30 40 50 60 70
    nearly sorted:  20 10 30 50 40 70 60

    So, if an element in sorted array lie at (i)th index then that same element in nearly sorted array will lie at:
        1. (i-1)th index
        2. (i)th index
        3. (i+1)th index
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;

    while(start<=end)
    {    
        int mid = start+(end-start)/2;

        if(mid-1 >= 0 && arr[mid-1]==target) return mid-1;
        if(arr[mid]==target) return mid;
        if(mid+1 < n && arr[mid+1]==target) return mid+1;

        if(target > arr[mid]) start = mid+2;
        else end = mid-2;

    }

    return -1;
}


int main() 
{
    int array[] = {20,10,30,50,40,70,60};
    int target = 60;
    int n = sizeof(array) / sizeof(array[0]);

    int result = binarySearch(array, n, target);

    (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;

    return 0;
}