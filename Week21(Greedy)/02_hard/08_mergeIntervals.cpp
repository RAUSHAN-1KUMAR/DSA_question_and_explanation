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

Example 3:
    Input: intervals = [[4,7],[1,4]]
    Output: [[1,7]]
    Explanation: Intervals [1,4] and [4,7] are considered overlapping.

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if(n==0) return {};

    // sort the intervals by their start time so that we can always start with the ealiest start first and then merge others
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for(int i=1 ; i<n ; i++)
    {
        if(merged.back()[1] >= intervals[i][0]) // if the end time of the last interval in merged is greater than or equal to the start time of the current interval
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]); // update the end time of the last interval in merged
        }
        else
        {
            merged.push_back(intervals[i]); // if they don't overlap, add the current interval to merged
        }
    }

    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> merged = mergeIntervals(intervals);
    for(auto &interval : merged)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}
