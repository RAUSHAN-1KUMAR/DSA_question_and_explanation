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

/*
Approach:-
    1. recursive:- TC: O(2^n), SC: O(n)
    2. memoization:- TC: O(n), SC: O(n)+O(n)
        -- one catch in this approach,
    3. tabulation:- TC: O(n), SC: O(n)
    4. space opti:- TC: O(n), SC: O(1)
*/


#include<iostream>
#include<vector>
using namespace std;

// recursive solution
int solve(vector<int> &nums, int index, int size)
{
    if(index>=size) return 0;

    int takeIt = nums[index] + solve(nums, index+2, size);
    int notTake = 0 + solve(nums, index+1, size);

    return max(takeIt, notTake);
}

int rob(vector<int>& nums)
{
    int n=nums.size();
    if(n==1) return nums[0];

    int takeIndexZero = nums[0] + solve(nums, 2, n-1);
    int notTakeIndexZero = 0 + solve(nums, 1, n);

    return max(takeIndexZero, notTakeIndexZero);
}


// memoization
int solve1(vector<int> &nums, int index, int size, vector<int> &dp)
{
    if(index>=size) return 0;

    //Step3;
    if(dp[index]!=-1)
        return dp[index];

    int takeIt = nums[index] + solve1(nums, index+2, size, dp);
    int notTake = 0 + solve1(nums, index+1, size, dp);

    // step2:
    dp[index] = max(takeIt, notTake);

    return dp[index];
}

int rob1(vector<int>& nums)
{
    int n=nums.size();
    if(n==1) return nums[0];

    // Step1: 
    vector<int> dp1(n, -1);
    int takeIndexZero = nums[0] + solve1(nums, 2, n-1, dp1);

    //Step1:
    vector<int> dp2(n, -1);//-> catch, we have to pass another dp, or we can pass same array but first we have to fill it with -1.
    int notTakeIndexZero = 0 + solve1(nums, 1, n, dp2);

    return max(takeIndexZero, notTakeIndexZero);
}


// space optimization
int rob2(vector<int> &nums)
{
    int n=nums.size();
    if(n==1) return nums[0];

    int next1=0;
    int next2=0;

    // if we don't take 0th element, we can take till (n-1)th element
    for(int i=n-1 ; i>=1 ; i--)
    {
        int takeIt = nums[i] + next2;
        int notTake = 0 + next1;

        next2=next1;
        next1=max(takeIt, notTake);
    }

    int ansA = 0 + next1; //-> we excluded 0th element

    // if we take 0th element, we can take till (n-2)th element
    next1 = 0;
    next2 = 0;
    for(int i=n-2 ; i>=2 ; i--)
    {
        int takeIt = nums[i]+next2;
        int notTake = 0 + next1;

        next2=next1;
        next1=max(takeIt, notTake);
    }

    int ansB = nums[0] + next1; //-> we included 0th element

    return max(ansA, ansB);
}


int main()
{
    vector<int> houses = {1,3,1,3,100};

    cout << "Maximum Amount to be roobed is: " << rob2(houses) << endl;
    
    return 0;
}


