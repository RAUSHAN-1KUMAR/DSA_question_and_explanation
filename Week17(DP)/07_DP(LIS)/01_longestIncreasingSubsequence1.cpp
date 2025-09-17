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
Appraoch:- DP
    1. Top-down approach:- On Applying this approach using 2D array, we have done a little bit variation while accessing the result from dp array or storing the result in dp array 
    
    -> shifting of index

    2. Bottom-up approach:- shifting applied
    3. space optimization:- shifting applied
    4. More space optimization:- shifting applied

Time Complexity:- O(n^2)

Better solution -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);

// Top-down approach
// our value of prev at starting is -1, so we did index shifting as required -> prev+1
int lengthOfLIShelper(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    if(curr == nums.size()) return 0;

    if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];

    // include
    int include = 0;
    if(prev==-1 || nums[curr]>nums[prev])
    {
        include = 1+lengthOfLIShelper(nums, curr+1, curr, dp);
    }

    // exclude
    int exclude = 0 + lengthOfLIShelper(nums, curr+1,prev, dp);


    dp[curr][prev+1] = max(include, exclude);

    return max(include, exclude);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    int curr = 0;
    int prev = -1;

    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

    int ans = lengthOfLIShelper(nums, curr, prev, dp);

    // printDpArray(dp);

    return ans;
}


// bottom-up approach: remember the second parameter will be in +1 state
int lengthOfLIS1(vector<int> &nums)
{
    int n = nums.size();

    // Step1: create dp array
    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

    // Step2: initialize dp array using base case of top down approach
    // initialized nth row i.e., curr==nums.size()
    for(int col=0 ; col<=n ; col++){
        dp[n][col] = 0;
    }

    // Step3: fill the remaining dp array using the logic of top-down approach, remember we have done index shifting in logic of top-down appraoch, so we have to maintain the for loop for that
    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)// curr: (0-n) tak ja rha tha
    {
        for(int prev_index=curr_index-1 ; prev_index>=-1 ; prev_index--)// prev: [-1 - curr) tak ja rha tha
        {
            int include = 0;
            if(prev_index==-1 || nums[curr_index]>nums[prev_index]){
                include = 1+dp[curr_index+1][curr_index+1];// index shifting required
            }

            int exclude = 0 + dp[curr_index+1][prev_index+1];// index shifting required

            dp[curr_index][prev_index+1] = max(include, exclude);// index shifting required
        }
    }

    printDpArray(dp);

    return dp[0][-1+1]; // index shifting required or dp[0][0]
}


// space optimization
int lengthOfLIS2(vector<int> &nums)
{
    int n = nums.size();

    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)
    {
        for(int prev_index=curr_index-1 ; prev_index>=-1 ; prev_index--)
        {
            int include = 0;
            if(prev_index==-1 || nums[curr_index]>nums[prev_index])
            {
                include = 1+nextRow[curr_index+1]; // dp[curr_index+1][curr_index+1] -> curr+1 matlab nextRow
            }

            int exclude = 0 + nextRow[prev_index+1];// dp[curr_index+1][prev_index+1] -> curr+1 matlab nextRow

            currRow[prev_index+1] = max(include, exclude); // dp[curr_index][prev_index+1] -> curr_index matlab currRow
        }

        // shifting the array
        nextRow = currRow;
    }

    return nextRow[0];
}

// More Space optimization
int lengthOfLIS3(vector<int> &nums)
{
    int n = nums.size();

    // bas ek row se kaam ho jayega: on Doing Change1 only
    vector<int> singleRow(n+1, 0);

    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)
    {
        //Change1 -> prev_index -1 se (curr_index-1) tak le jao
        for(int prev_index=-1 ; prev_index<=curr_index-1 ; prev_index++)
        {
            int include = 0;
            if(prev_index==-1 || nums[curr_index]>nums[prev_index])
            {
                include = 1+singleRow[curr_index+1];
            }

            int exclude = 0 + singleRow[prev_index+1];

            singleRow[prev_index+1] = max(include, exclude);
        }
        
        // no shifting-> only one row so shifting kya kerna
    }

    return singleRow[0];
}


int main()
{
    vector<int> nums = {0,1,0,2,3,2};

    cout << lengthOfLIS1(nums) << endl;

    return 0;
}

void printDpArray(vector<vector<int>> &dp)
{
    for(auto &vec:dp)
    {
        for(int num:vec)
        {
            if(num!=-1) cout << " " << num << " ";
            else cout << num << " ";
        }
        cout << endl;
    }
}