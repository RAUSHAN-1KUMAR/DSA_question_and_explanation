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
Approach:- LIS appraoch
    1. recursive
        -- The only difference is we just have to check between prev[1] and curr[0] because we just need these two to check whether intervals intesect or not 
*/

#include<bits/stdc++.h>
using namespace std;

// recursive
int helper(vector<vector<int>> &intervals, int prev, int curr)
{
    if(curr>=intervals.size()) return 0;


    int include=0;
    if(prev==-1 || intervals[curr][0]>=intervals[prev][1])
    {
        include = 1 + helper(intervals, curr, curr+1);
    }

    int exclude = 0 + helper(intervals, prev, curr+1);

    return max(exclude, include);
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int prev=-1;
    int curr=0;

    int ans = helper(intervals, prev, curr);

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

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}