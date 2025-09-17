/*
Question:- find missing element in a sorted array(size: n, element lie b/w: 1-(n+1)).

Note:- It can be solved using linear search or sum concept, in these cases the T.C(O(n)), So to minimize the time complexity we will apply the binary search.
*/

/*
Approach:- If the given elements -> 1 2 3 4 6 7 8 9, having indexes 0 1 2 3 4 5 6 7. So, we can see that till element 4 we get the elements by 'index+1' after 4 we get the elements by 'index+2' so we have to find from where the index+2 started. Answer will be that index+1 or element-1. 
    -- if the difference of element and index is 1 then look for the right part only.
    -- if the differerece of element and index is not equal to 1 then look for the left part only.
    -- but for the last missing element we have to give other condition

Note:- In this approach, their is a catch if the missing element is the last element, because on that case we will always get the difference = 1 and so we move to right. So, for last element case we will handle it in different way.
*/

#include<bits/stdc++.h>
using namespace std;

int findMissingElement(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start<=end)
    {
        int mid = start+(end-start)/2;
        int diff = arr[mid]-mid;

        if(diff == 1){
            start = mid+1;
        }
        else{
            ans = mid;
            end = mid-1;
        }
    }

    if(ans==-1) return n+1;// in case last element is missing.

    return ans+1;
}

int main()
{
    int arr[] = {1,2,3,4,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);

    cout << findMissingElement(arr,size) << endl;

    return 0;
}