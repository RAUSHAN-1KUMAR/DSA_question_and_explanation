/* GFG

Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:
    Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
    Output: 6
    Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

    Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
    Output: 5
    Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

    Input: arr[] = [10, -10, 20, 30], k = 5
    Output: 0
    Explanation: No subarray with sum = 5 is present in arr[].
*/

/*
Approach
    -- we will use prefix sum and map to store the prefix sum and its first occurence index
    -- if prefixSum-k is present in map then we will calculate the length of subarray from the index of (prefixSum-k)+1 to current index i.e., (i - map[prefixSum-k])
    -- if prefixSum itself is equal to k then we will update the length as i+1
    -- we will store only the first occurence index of a particular prefix sum in map
    -- finally return the length
*/

#include<bits/stdc++.h>
using namespace std;

int longetSubarray(vector<int>& arr, int k)
{
    int n = arr.size();

    unordered_map<int,int> mp; // to store the prefix sum and its first occurence index

    int prefixSum=0;
    int length=0;

    for(int i=0 ; i<n ; i++)
    {
        prefixSum += arr[i];

        if(prefixSum==k)
        {
            length = max(length, i+1);
        }

        int rem = prefixSum - k;

        if(mp.find(rem)!=mp.end())
        {
            length = max(length, (i - mp[rem]));
        }

        // store only the first occurence index of a particular prefix sum
        if(mp.find(prefixSum)==mp.end())
            mp[prefixSum] = i;
    }

    return length;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k=15;
    cout << longetSubarray(arr, k) << endl;
    return 0;
}