/* -> 540

Question:- Given an array(unsorted or sorted) in which all the elements occurs even times except one element, find that element, conditions are:
    1. repeating numbers repeats in pair and no any pairs are adjacent.
    2. repeating pairs are of length 2 i.e., ek baar m koi bhi number do se jyada baar nhi aa rha h


Example:
    input: 1,1,5,5,2,2,3,3,2,4,4
    output: 2

    input: 10,10,2,2,5,5,2,5,5,20,20,11,11,10,10
    output: 2

    input: 5
    output: 5
*/

/*
Approach:- explained in notecopy

Note:- We can use XOR of each element to find that odd occurence element but the time complexity will be O(n): to reduce the time complexity we will use binary search. -> see next solution
*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n)
{
    int s=0;
    int e=n-1;

    while(s<=e)
    {
        int mid = s+(e-s)/2;

        // for single element
        if(s==e) return arr[s];


        if(mid%2==1) // if mid is odd
        {
            if(mid-1 >= 0 && arr[mid-1] == arr[mid]) s = mid+1;
            else e = mid-1;
        }
        else // if mid is even
        {
            if(mid+1 < n && arr[mid]==arr[mid+1]) s = mid+2;
            else e = mid;
        }

    }

    return -1;
}


int main()
{
    int array[] = {10,10,2,2,3,3,2,5,5,6,6,7,7};
    int n = sizeof(array) / sizeof(array[0]);

    int result = binarySearch(array, n);

    (result == -1) ? cout << "Element not found" : cout << "Element found: " << result;

    return 0;
}


