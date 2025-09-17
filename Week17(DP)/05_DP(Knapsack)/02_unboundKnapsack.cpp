/* GFG

Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.

The TASK is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.

Examples:
    Input: val = [1, 1], wt = [2, 1], capacity = 3
    Output: 3
    Explanation: The optimal choice is to pick the 2nd element 3 times.


    Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
    Output: 48
    Explanation: The optimal choice is to pick the 1st element 8 times.


    Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
    Output: 0
    Explanation: We can't pick any element .hence, total profit is 0.
*/

/*
Approach:-
    -- Now we can use the same item infinite times, so lets solve it using for loop for each capacity value, just like coin change problem

Lets solve it using include and exlcude -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &dp);

// recursive solution
int helper(vector<int>& val, vector<int>& wt, int capacity)
{
    if(capacity==0) return 0;

    int ans = 0;
    for(int i=0 ; i<wt.size() ; i++)
    {   
        if(wt[i]<=capacity)
        {
            int aageKaAns = val[i] + helper(val, wt, capacity-wt[i]);

            ans = max(ans, aageKaAns);
        }
    }

    return ans;
}

int knapSack(vector<int>& val, vector<int>& wt, int capacity)
{
    return helper(val, wt, capacity);
}


// memoization
int helper1(vector<int>& val, vector<int>& wt, int capacity, vector<int> &dp)
{
    if(capacity==0) return 0;

    if(dp[capacity]!=-1)   
        return dp[capacity];

    int ans = 0;
    for(int i=0 ; i<wt.size() ; i++)
    {   
        if(wt[i]<=capacity)
        {
            int aageKaAns = val[i] + helper1(val, wt, capacity-wt[i], dp);

            ans = max(ans, aageKaAns);
        }
    }

    dp[capacity] = ans;

    return dp[capacity];
}

int knapSack1(vector<int>& val, vector<int>& wt, int capacity)
{
    vector<int> dp(capacity+1 , -1);

    return helper1(val, wt, capacity, dp);
}


// tabulation
int knapSack2(vector<int>& val, vector<int>& wt, int capacity)
{
    //Step1:
    vector<int> dp(capacity+1 , 0);

    //Step2: initialization
    dp[0] = 0;

    //Step3:
    for(int cap=1 ; cap<=capacity ; cap++)
    {
        int ans = 0;
        for(int i=0 ; i<wt.size() ; i++)
        {   
            if(wt[i]<=cap)
            {
                int aageKaAns = val[i] + dp[cap-wt[i]];

                ans = max(ans, aageKaAns);
            }
        }

        dp[cap] = ans; 
    }

    printArray(dp);

    return dp[capacity];
}

void printArray(vector<int> &dp)
{
    for(auto num:dp)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> val = {6,1,7,7};
    vector<int> wt = {1,3,4,5};
    int capacity = 8;

    cout << knapSack2(val, wt, capacity) << endl;

    return 0;
}

