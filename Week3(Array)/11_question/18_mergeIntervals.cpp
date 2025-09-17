/* -> 56

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

/*
Approach:-
    1. Brute Force:- sorting
        -- sort the pairs, and then run a loop for each pair and a nested loop to combine the pair till it can.

        TC:- O(nlogn) + O(2n)

    2. Better Approach:- sorting
        -- why nested loop, use only single loop, i.e., in one iteration combine the intervals

        TC:- O(nlogn) + O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// brute force using sorting
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    for(int i=0; i<n ; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // if curr pair end is already smaller than the current interval
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }

        // if not then update it accordingly
        for(int j = i+1 ; j<n ; j++)
        {
            // if next pair start is less than curr pair end, then combine it
            if(intervals[j][0]<=end){
                end = max(end, intervals[j][1]);
            }
            else // if not then next pair is not overlapping
            {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

// Better approach
vector<vector<int>> merge1(vector<vector<int>>& intervals)
{
    int n  = intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    ans.push_back(intervals[0]); //intitializing the ans vector

    int i=1;
    while (i<n)
    {
        // now compare with the last interval of ans vector with upcomming intervals
        if(ans.back()[1] >= intervals[i][0]){
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
        i++;
    }

    return ans;
}


int main()
{
    vector<vector<int>> intervals = {
        {1,4},
        {4,6},
        {5,10},
        {15,18}
    };

    vector<vector<int>> ans = merge1(intervals);

    for(auto vec:ans){
        for(int num:vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

