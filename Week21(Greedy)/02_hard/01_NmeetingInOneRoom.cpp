/* GFG

You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :
    Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

    Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
    Output: 1
    Explanation: Only one meetings can be held with given start and end timings.

    Input: start[] = [1, 2], end[] = [100, 99]
    Output: 1

*/

/*
Approach:
    -- main logic is to sort the meetings by their end time
    -- then iterate through the meetings and keep track of the end time of the last meeting
*/

#include<bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    // create a vector of pairs to store start and end time of each meeting
    vector<pair<int,int>> meetings(n);

    for(int i=0 ; i<n ; i++)
    {
        meetings[i].first = end[i];
        meetings[i].second = start[i];
    }

    // sort the meetings array in ascending order of end time
    sort(meetings.begin(), meetings.end());

    int count=0;
    int lastEndTime=-1; // start will happen from -1

    for(int i=0 ; i<n ; i++)
    {
        if(meetings[i].second > lastEndTime)
        {// if the start time of the current meeting is greater than the end time of the last meeting
            count++;
            lastEndTime = meetings[i].first; // update the end time of the last meeting
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start, end) << endl;
    return 0;
}