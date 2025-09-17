/*
Find the total occurence of a number in a sorted array using binary search
*/

/*
Approach:- 
    -- (lastOccurenceIndex - firstOccurenceIndex + 1)
    -- T.C -> O(logn)
*/

#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    int ans = -1;

    while(start<=end)
    {
        if(arr[mid]==target){
            ans = mid;
            end = mid-1;
        }
        else if(target>arr[mid]) start = mid+1;
        else end = mid-1;

        mid = (start+end)/2;
    }

    return ans;
}


int lastOccurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    int ans = -1;

    while(start<=end)
    {
        if(arr[mid]==target){
            ans = mid;
            start = mid+1;
        }
        else if(target>arr[mid]) start = mid+1;
        else end = mid-1;

        mid = (start+end)/2;
    }

    return ans;
}

int totalOccurence(int arr[], int n, int target){
    int firstOuc = firstOccurence(arr,n,target);
    int lastOuc = lastOccurence(arr,n,target);

    return lastOuc-firstOuc+1;
}


int main() 
{
    int array[] = {10,20,30,30,30,30,40,50};
    int target = 30;
    int n = sizeof(array) / sizeof(array[0]);

    int result = totalOccurence(array, n, target);

    (result == -1) ? cout << "Element not found" : cout << "Total occurence of element found: " << result;

    return 0;
}