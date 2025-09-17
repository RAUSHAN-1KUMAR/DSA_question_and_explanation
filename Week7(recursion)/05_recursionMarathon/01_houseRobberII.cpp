/* -> 213

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3
*/

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &nums, int index, int size)
{
    // base case
    if(index>=size) return 0;

    // chori kerlo ith index p
    int option1 = nums[index] + solve(nums,index+2, size);

    // chori mat karo ith index p
    int option2 = 0 + solve(nums,index+1, size); 

    return max(option1, option2);
}

int rob(vector<int>& nums)
{

    int n = nums.size();

    if(n==1) return nums[0];

    // if 0th index p chori hua(matlab last tak nhi ja sakte)
    int option1 = solve(nums,0,n-1);

    // if 0th index p chori nhi hua(matlab last tak ja sakte h)
    int option2 = solve (nums,1,n);

    int ans = max(option1, option2);

    return ans;
}

int main()
{
    vector<int> houses = {1};

    cout << "Maximum Amount to be roobed is: " << rob(houses) << endl;
    
    return 0;
}