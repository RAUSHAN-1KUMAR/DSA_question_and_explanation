/* -> 719

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:
    Input: nums = [1,3,1], k = 1
    Output: 0
    Explanation: Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:
    Input: nums = [1,1,1], k = 2
    Output: 0

Example 3:
    Input: nums = [1,6,1], k = 3
    Output: 5
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());

    

    // map<int,int> mp;
    // sort(nums.begin(), nums.end());

    // for(int i=0 ; i<nums.size() ; i++)
    // {
    //     for(int j=i+1 ; j<nums.size() ; j++)
    //     {
    //         int diff = abs(nums[j]-nums[i]);
    //         mp[diff]++;
    //     }
    // }

    // int ans = 0;
    // for(auto it:mp)
    // {
    //     int second = it.second;
    //     k -= second;

    //     if(k<=0) 
    //     {
    //         ans = it.first;
    //         break;
    //     }
    // }
    
    // return ans;
}

int main()
{
    vector<int> nums = {1,2,3,1,6,4,4};
    int k=6;

    cout << smallestDistancePair(nums, k) << endl;

    return 0;
}
