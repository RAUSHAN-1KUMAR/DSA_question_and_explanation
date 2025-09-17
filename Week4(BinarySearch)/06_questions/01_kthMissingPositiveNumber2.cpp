/* -> 1539

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Could you solve this problem in less than O(n) complexity? 

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

/*
Appraoch:- one pointer (brute force algo)
    -- iterating through each element of num and if nums[i]<=k it means that nums[i] has taken a place so we will increment k++;
*/

#include<iostream>
#include<vector>
using namespace std;

int findKthPosition(vector<int>& arr, int k)
{
    for(int i=0 ; i<arr.size() ; i++)
    {
        if(arr[i]<=k) k++;
        else break;
    }

    return k;
}

int main()
{
    vector<int> arr = {12,15,23,25,35,66,78};
    int k = 57;

    int ans = findKthPosition(arr, k);

    cout << ans << endl;

    return 0;
}