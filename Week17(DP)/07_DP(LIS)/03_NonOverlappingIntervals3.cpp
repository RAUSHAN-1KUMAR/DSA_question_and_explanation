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
Approach:- sorting 
    -- interval[1] ke respect m sort kero naki interval[0] ke
    -- and then only one for loop m solve ho jayega
        Logic:- 
            i) interval[1] ke respect m sort issiliye ker rhe taaki jo interval sabse pehle khatam ho rha wo count m aaaye starting m
            ii) the logic is that we are take the ending of first interval and then compare it with the starting of succeeding intervals, i.e, if it is less than the starting of succeeding intervals, then now assign it to the ending value of that compared interval.

*/

#include<bits/stdc++.h>
using namespace std;


// using sorting
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n=intervals.size();

    // sorted with respect to index 1, i.e., w.r.t ending of each intervals
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });

    // took the ending value of first interval
    int curr = intervals[0][1];
    int ans=1;

    // now compare it with the others upcoming interval's first value
    for(int i=1 ; i<n ; i++)
    {
        if(curr<=intervals[i][0])
        {
            ans++;
            curr=intervals[i][1];
        }
    }

    return n-ans;
}


int main()
{
    vector<vector<int>> intervals = {
        {-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}
    };

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}