/* -> 1755

You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

 

Example 1:
    Input: nums = [5,-7,3,5], goal = 6
    Output: 0
    Explanation: Choose the whole array as a subsequence, with a sum of 6.
    This is equal to the goal, so the absolute difference is 0.


Example 2:
    Input: nums = [7,-9,15,-2], goal = -5
    Output: 1
    Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
    The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.


Example 3:
    Input: nums = [1,2,3], goal = -7
    Output: 7
*/

/*
Appraoch:- Meet in the middle technique
    -- In this question he has asked to, abs(S-sum)->0
    -- writting own Binary search code
*/

#include<bits/stdc++.h>
using namespace std;

// we can also use a recursive function to find all differenct subset sum
void calculateSum(vector<int> &arr, vector<int> &halfes, int n, int offset)
{
    for(int i=0 ; i<(1<<n) ; i++)//: 1<<n => 1*2^n
    {
        int sum=0;
        for(int j=0 ; j<n ; j++)
        {
            if(i&(1<<j))
                sum+=arr[j+offset];
        }
        halfes.push_back(sum);
    }
}

int minAbsDifference(vector<int>& nums, int goal) 
{
    int n = nums.size();

    vector<int> firsthalfSum;
    vector<int> secondhalfSum;

    calculateSum(nums, firsthalfSum, n/2, 0);
    calculateSum(nums, secondhalfSum, n-n/2, n/2);

    sort(secondhalfSum.begin(), secondhalfSum.end());

    int ans = INT_MAX;
    for(int i=0 ; i<firsthalfSum.size(); i++)
    {
        int x = firsthalfSum[i];

        int low=0;
        int high=secondhalfSum.size()-1;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int sum = x+secondhalfSum[mid];

            if(sum==goal)
                return 0;

            // since, in this question sum can be >=goal or can be <=goal as well. So, each time we have to check the min and store it
            ans = min(ans, abs(sum-goal));

            if(sum>goal)
                high = mid-1;
            else
                low = mid+1;
        }

    }

    return ans;
}

int main()
{
    vector<int> arr = {5,-7,3,5};
    int goal = 6;

    cout << minAbsDifference(arr, goal) << endl;

    return 0;
}