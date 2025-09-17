/* Q.no: -> 539
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
*/

/*
Approach:- 
    -- first convert the given time system which is in string into minutes and store the obtained minutes in vector of int. Do for each element of vector of string
    -- sort the obtained vector of minutes, then compare the consecutive difference but don't forget to compare last and first element comparison with your answer
    -- we can assume 00:00 as 24:00 -> 1440 in minutes, for the difference between last and first element
*/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int convertToMin(string &t)
{
    int hr = stoi(t.substr(0,2));
    int min = stoi(t.substr(3,2));

    return 60*hr+min;
}


int findMinDifference(vector<string> &timePoints)
{
    vector<int> mins;

    for(auto time:timePoints)
    {
        mins.push_back(convertToMin(time));
    }

    sort(mins.begin(), mins.end());

    int ans = INT_MAX;//min diff
    for(int i=0 ; i<(mins.size()-1) ; i++)
    {
        ans = min(ans,mins[i+1]-mins[i]);
    }

    // for time difference between last element and first elment, because that is the only difference we missed
    ans = min(ans, 1440+mins[0]-mins[mins.size()-1]);

    return ans;
}

int main()
{
    vector<string> str = {"23:59", "00:00"};

    cout << findMinDifference(str) << endl;

    return 0;
}