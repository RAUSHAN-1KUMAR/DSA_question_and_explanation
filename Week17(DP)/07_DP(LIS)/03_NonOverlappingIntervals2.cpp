/* -> 435

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/*
Approach:- LIS appraoch-> hence shifting will be required
    2. top-down approach
    3. bottom-up approach -> tabulation
    4. More space optimization

But teeno m TLE aa rha h, ya phir MLE, i dont know why?, so we need another approach which will basically be related to sorting or something like binary search
*/

#include<bits/stdc++.h>
using namespace std;

// top-down
int helper(vector<vector<int>> &intervals, int prev, int curr, vector<vector<int>> &dp)
{
    if(curr>=intervals.size()) return 0;

    // Step3: use the result that already exists in dp array
    if(dp[curr][prev+1]!=-1)
    {
        return dp[curr][prev+1];
    }

    int include=0;
    if(prev==-1 || intervals[curr][0]>=intervals[prev][1])
    {
        include = 1 + helper(intervals, curr, curr+1, dp);
    }

    int exclude = 0 + helper(intervals, prev, curr+1, dp);

    // Step2: Store the result in dp array
    dp[curr][prev+1] = max(include, exclude);

    return dp[curr][prev+1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int prev=-1;
    int curr=0;
    int n=intervals.size();

    //Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    int ans = helper(intervals, prev, curr, dp);

    int actualAns = intervals.size()-ans;

    return actualAns;
}


// bottom-up appoach
int eraseOverlapIntervals1(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int n=intervals.size();

    //Step1 and Step2: create dp array and initialized dp array
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    //Step3: fill the remaining dp array using the logic of top down approach and also handle the indexing carefully
    for(int curr=n-1 ; curr>=0 ; curr--)
    {
        for(int prev=-1 ; prev<=curr-1 ; prev++)
        {
            int include=0;
            if(prev==-1 || intervals[curr][0]>=intervals[prev][1])
            {
                include = 1 + dp[curr+1][curr+1];//shifting req
            }

            int exclude = 0 + dp[curr+1][prev+1];//shifting req

            dp[curr][prev+1] = max(include, exclude); //shifting req
        }
    }

    int ans = dp[0][0];

    int actualAns = intervals.size()-ans;

    return actualAns;
}

// more space optimized
int eraseOverlapIntervals2(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int n=intervals.size();

    //Step1:
    vector<int> singleRow(n+1, 0);

    //Step2: use same code of bottom-up approach
    for(int curr=n-1 ; curr>=0 ; curr--)
    {
        for(int prev=-1 ; prev<=curr-1 ; prev++)
        {
            int include=0;
            if(prev==-1 || intervals[curr][0]>=intervals[prev][1])
            {
                include = 1 + singleRow[curr+1];//shifting req
            }

            int exclude = 0 + singleRow[prev+1];//shifting req

            singleRow[prev+1] = max(include, exclude); //shifting req
        }
    }

    int ans = singleRow[0];//shifting req

    int actualAns = intervals.size()-ans;

    return actualAns;
}


int main()
{
    vector<vector<int>> intervals = {
        {1,2},
        {2,3},
        {3,4},
        {1,3}
    };

    cout << eraseOverlapIntervals2(intervals) << endl;

    return 0;
}