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

#include<bits/stdc++.h>
using namespace std;

// we are gonna count the maximum number of non-overlapping intervals and subtract it from the total number of intervals to get the minimum number of intervals to remove
int eraseOverlapping(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if(n==0) return 0;

    // sort the intervals by their end time so that we can always pick the interval that finishes earliest
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int count = 1; // count of non-overlapping intervals
    int end = intervals[0][1]; // end time of the first interval

    for(int i=1 ; i<n ; i++)
    {
        if(intervals[i][0] >= end) // if the start time of the current interval is greater than or equal to the end time of the last interval
        {
            count++;
            end = intervals[i][1]; // update the end time of the last interval
        }
    }

    return n - count; // minimum number of intervals to remove
}


int main()
{
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << eraseOverlapping(intervals) << endl;
    return 0;
}


