/* -> 410

Given an integer array 'nums' and an integer k, split 'nums' into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:
    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


Example 2:
    Input: nums = [1,2,3,4,5], k = 2
    Output: 9
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/

/*
Approach:- Using Dynamic Programming(Merge Interval Type)
    Lets Think:- we have some splitting and then comparing the sum of the subarray, Kind of like this.. So What can we do here,

        Step1: Express the problem in terms of indexes.
            -- we can see that, we have a variable K, it means taking a subarray would definitely decrease the k. So, one of our index will be for K
            -- and there is a contiguous splitting which will be dependent on an another variable which will represent the index position(kaha se splitting kerna h). So, another index will be for splitting start 

        Step2: Try out all possible choices at a given index.
            -- Question says to split, so we will split our array into two halfes at every index(i), 
                1. left half: which will call an another function to return the sum of the left half array
                2. right half: which will be a recursive call, by (m-1, i+1), m-1 becuase we have splitted it into two half

            -- So think about it, will this splitting go till end: NO, because we are bound do split the array into k subarray, so we will have a for loop to split the array from i to n-m+1.

        Step3: Question asked to return minimum of maximum. So, we will return the minimum of the largest among both the halfes.

    TC:- O(k^n)
    SC:- O(k) -> stack space depends on array slits, not the size of array
*/

#include<bits/stdc++.h>
using namespace std;

int rangeSum(vector<int> &nums, int start, int end)
{
    int sum=0;
    for(int i=start; i<=end; i++)
    {
        sum+=nums[i];
    }

    return sum;
}

// recursive solution
int helper(vector<int> &nums, int &n, int k, int i)
{
    // base case
    if(k==1)
    {
        return rangeSum(nums, i, n-1);
    }


    int ans = INT_MAX;
    // splitting array at possible index
    // n-k+1 ensure that enough elemnts remain for 'k-1' subarrays
    for(int split=i ; split<n-k+1 ; split++) 
    {
        int leftSum = rangeSum(nums, i, split); // sum of left half
        int rightSum = helper(nums,n, k-1, split+1); // recursive call on rightHalf, k-1 because we have seperated out one half -> leftHalf

        int largestSum = max(leftSum, rightSum);// take the maximum

        ans = min(ans, largestSum);// take the minimum of maximum


        // Optimization: if ans is already less than left sum, it always stays at it, so no need to check further becuase on further checking ans value stays the same
        if(ans < leftSum) 
        {
            break;
        }
    }

    return ans;
}

int splitArray(vector<int> &nums, int k)
{
    int i=0;
    int n=nums.size();
    return helper(nums, n, k, i);
}



// memoization
int helper1(vector<int> &nums, int &n, int k, int i, vector<vector<int>> &dp)
{
    // base case
    if(k==1)
    {
        return rangeSum(nums, i, n-1);
    }

    //Step3:
    if(dp[i][k]!=-1)
        return dp[i][k];


    int ans = INT_MAX;
    for(int split=i ; split<n-k+1 ; split++) 
    {
        int leftSum = rangeSum(nums, i, split);
        int rightSum = helper1(nums,n, k-1, split+1, dp);

        int largestSum = max(leftSum, rightSum);

        ans = min(ans, largestSum);

        if(ans < leftSum) 
        {
            break;
        }
    }

    // Step2:
    dp[i][k] = ans;

    return dp[i][k];
}

int splitArray1(vector<int> &nums, int k)
{
    int i=0;
    int n=nums.size();

    // Step1: k+1, because if k=3, then it can be 3,2,1
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return helper1(nums, n, k, i, dp);
}


int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2; 

    cout << splitArray1(nums, k) << endl;

    return 0;
}

