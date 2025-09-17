/* GFG

Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).


Examples:
    Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
    Output: 3
    Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.

    Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
    Output: 1
    Explanation: All train times are mutually exclusive. So we need only one platform.

    Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
    Output: 3
    Explanation: All 3 trains have to be there from 11:00 to 11:30
*/

/*
Approach:
    1.  brute force :
        -- O(n^2) time complexity
        -- O(1) space complexity

    2.  Greedy
        -- O(nlogn) time complexity
        -- O(1) space complexity
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force
int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    int platforms = 0; // at least one platform is needed

    for(int i=0 ; i<n ; i++)
    {
        int count = 0; // count of platforms needed for the current train

        for(int j=0 ; j<n ; j++)
        {
            // check if the trains overlap
            if( arr[j] <= arr[i] && arr[i] <= dep[j])
                count++;
        }

        platforms = max(platforms, count); // update the maximum platforms needed
    }

    return platforms;
}

// greedy 
int minPlatform2(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1; // at least one platform is needed
    int count = 1; // count of platforms needed for the current train

    int next=1, curr=0; // next for next_train arrival, curr for curr_train departure

    while(next<n && curr<n)
    {
        if(arr[next] <= dep[curr]) // if the next train arrives before the current train departs
        {
            count++; // need an extra platform
            next++;
        }
        else // if the next train arrives after the current train departs
        {
            count--; // free a platform
            curr++;
        }

        platforms = max(platforms, count); // update the maximum platforms needed
    }

    return platforms;
}


int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep) << endl;
    cout << minPlatform2(arr, dep) << endl;
    return 0;
}

