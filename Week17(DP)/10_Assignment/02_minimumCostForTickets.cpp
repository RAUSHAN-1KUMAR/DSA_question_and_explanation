/* -> 983

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:
    - a 1-day pass is sold for costs[0] dollars,
    - a 7-day pass is sold for costs[1] dollars, and
    - a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
 

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
*/

/*
Approach:- DP
    1. recursion
    2. top-down approach
    3. bottom-up approach
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// recursion
int helper(vector<int>& days, vector<int>& costs, int i)
{
    if(i>=days.size())
    {
        return 0;
    }

    int ans = 0;

    // 1-day pass
    int cost1DP = costs[0] + helper(days, costs, i+1);

    // 7-day pass
    int start = days[i];
    int end = start+7-1;
    int index = i;
    while (index < days.size() && days[index]<=end)
    {
        index++;
    }
    int cost7DP = costs[1] + helper(days, costs, index);
    

    // 30-day pass
    start = days[i];
    end = start+30-1;
    index = i;
    while (index < days.size() && days[index]<=end)
    {
        index++;
    }
    int cost30DP = costs[2] + helper(days, costs, index);


    ans = min(cost1DP, min(cost7DP, cost30DP));

    return ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) 
{
    int index = 0;
    int ans = helper(days, costs, index);

    return ans;
}


// top-down approach
int helper1(vector<int>& days, vector<int>& costs, int i, vector<int> &dp)
{
    if(i>=days.size())
    {
        return 0;
    }

    // Step3:
    if(dp[i]!=-1)
    {
        return dp[i];
    }

    int ans = 0;

    // 1-day pass
    int cost1DP = costs[0] + helper1(days, costs, i+1, dp);

    // 7-day pass
    int start = days[i];
    int end = start+7-1;
    int index = i;
    while (index < days.size() && days[index]<=end)
    {
        index++;
    }
    int cost7DP = costs[1] + helper1(days, costs, index, dp);
    

    // 30-day pass
    start = days[i];
    end = start+30-1;
    index = i;
    while (index < days.size() && days[index]<=end)
    {
        index++;
    }
    int cost30DP = costs[2] + helper1(days, costs, index, dp);

    // Step2:
    dp[i] = min(cost1DP, min(cost7DP, cost30DP));

    return dp[i];
}

int mincostTickets1(vector<int>& days, vector<int>& costs) 
{
    int index = 0;
    int n = days.size();

    // Step1:
    vector<int> dp(n+1, -1);

    int ans = helper1(days, costs, index, dp);

    return ans;
}


// bottom-up approach
int mincostTickets2(vector<int>& days, vector<int>& costs) 
{
    int n = days.size();

    // Step1:
    vector<int> dp(n+1, -1);

    // Step2: 
    dp[n] = 0;

    // Step3:
    for(int i = n-1 ; i>=0 ; i--)
    {
        // 1-day pass
        int cost1DP = costs[0] + dp[i+1];

        // 7-day pass
        int start = days[i];
        int end = start+7-1;
        int index = i;
        while (index < days.size() && days[index]<=end)
        {
            index++;
        }
        int cost7DP = costs[1] + dp[index];
        

        // 30-day pass
        start = days[i];
        end = start+30-1;
        index = i;
        while (index < days.size() && days[index]<=end)
        {
            index++;
        }
        int cost30DP = costs[2] + dp[index];

        dp[i] = min(cost1DP, min(cost7DP, cost30DP));
    }


    return dp[0];
}



int main()
{
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};

    cout << mincostTickets2(days, costs) << endl;

    return 0;
}
