/*
Given an integer array nums, return the length of the longest strictly increasing subsequence


Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


Example 2:
    Input: nums = [0,1,0,3,2,3]
    Output: 4


Example 3:
    Input: nums = [7,7,7,7,7,7,7]
    Output: 1
*/

/* 
Appraoch:- Using dp tabulation method to print the LIS.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> parent(n + 1, vector<int>(n + 1, -1));

    for (int col = 0; col <= n; col++)
    {
        dp[n][col] = 0;
    }

    // Fill the dp table
    for (int curr_index = n - 1; curr_index >= 0; curr_index--) 
    {
        for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) 
        {
            int include = 0;
            if (prev_index == -1 || arr[curr_index] > arr[prev_index]) 
            {
                include = 1 + dp[curr_index + 1][curr_index + 1];
            }

            int exclude = 0 + dp[curr_index + 1][prev_index + 1];

            if (include > exclude) 
            {
                dp[curr_index][prev_index + 1] = include;
                parent[curr_index][prev_index + 1] = curr_index; // Track inclusion
            } else
            {
                dp[curr_index][prev_index + 1] = exclude;
                parent[curr_index][prev_index + 1] = parent[curr_index + 1][prev_index + 1]; // Track exclusion
            }
        }
    }

    // Reconstruct the LIS sequence
    vector<int> lis;
    int curr_index = 0, prev_index = -1;
    while (curr_index < n && parent[curr_index][prev_index + 1] != -1)
    {
        int selected_index = parent[curr_index][prev_index + 1];
        if (selected_index == curr_index)
        {
            lis.push_back(arr[curr_index]);
            prev_index = curr_index;
        }
        curr_index++;
    }

    return lis;
}

int main()
{
    vector<int> nums = {1,0,5};

    for(auto num:longestIncreasingSubsequence(nums.size(), nums))
    {   
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

