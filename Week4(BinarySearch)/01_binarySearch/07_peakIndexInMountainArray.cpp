/* -> 852
An array 'arr' is a mountain if the following properties hold:
    - arr.length >= 3
    - There exists some i with 0 < i < (arr.length-1) such that:
        - arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
        - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array 'arr', return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.


Example 1:
    Input: arr = [0,1,0]
    Output: 1

Example 2:
    Input: arr = [0,2,1,0]
    Output: 1


Example 3:
    Input: arr = [0,10,5,2]
    Output: 1
*/

/*
Approach:- described in the notecopy

Note:- If we apply the binary search and we did like this: 'start = mid' or 'end = mid' in any case inside while loop, then we will have infinite loop if we use the condition start<=end, so to avoid infinite loop we use condition start<end only or give any other condition inside while loop to handle it.
*/


#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 0;
    int end = arr.size()-1;

    while(start<end)
    {
        int mid = start + (end-start)/2;
        
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }

    return end;
}

int main()
{
    vector<int> vrr = {12,14,16,10,9,7,1};

    cout << peakIndexInMountainArray(vrr) << endl;

    return 0;
}