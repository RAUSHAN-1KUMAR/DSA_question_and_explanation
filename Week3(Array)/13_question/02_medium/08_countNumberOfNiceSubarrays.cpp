/* -> 1248

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
 

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

*/

/*
Approach:- sliding window
    -- we can consider odd no.-> 1(nums[i]%2)
                       even no.-> 0(nums[i]%2)
    -- and then apply the same appraoch as we did in just previous question.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(vector<int>&nums, int goal)
{
    int i=0;
    int j=0;
    int count = 0;
    int sum=0;
    
    while (j<nums.size())
    {
        sum += nums[j]%2;

        while (sum>goal && i<=j)
        {
            sum -= nums[i]%2;
            i++;
        }
        
        count += j-i+1;
        j++;
    }

    return count;
}

int numberOfSubarrays(vector<int>&nums, int k)
{
    return helper(nums,k)-helper(nums,k-1);  
}

int main()
{
    vector<int> nums = {2,2,3,1,1,2,4,5};
    int k = 3;

    int ans = numberOfSubarrays(nums, k);

    cout << ans << endl;

    return 0;
}
