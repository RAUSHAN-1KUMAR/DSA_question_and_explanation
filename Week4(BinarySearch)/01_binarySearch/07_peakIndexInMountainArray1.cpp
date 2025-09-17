/*
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
Approach:- a little difference to previous approach by lakshaay bhaiyaa

Note:- If we apply the binary search and we did like this: 'start = mid' or 'end = mid' in any case inside while loop, then we will hava infinite loop if we use the condition start<=end, so to avoid infinite loop we use condition start<end only or give any other condition inside while loop to handle it.
*/


#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &a)
{
    int ans = -1;
    int start = 0;
    int end = a.size() - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(a[mid + 1] > a[mid]){
            start = mid + 1;
        }
        else if(a[mid - 1] > a[mid]){
            end = mid - 1;
        }
        else {
            // It must be Peak
            ans = mid;
            break;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> vrr = {3,5,3,2,0};

    cout << peakIndexInMountainArray(vrr) << endl;

    return 0;
}