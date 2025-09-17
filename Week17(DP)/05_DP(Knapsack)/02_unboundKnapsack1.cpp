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
Approach:- solved it using include and exlcude: from lastIndex to firstIndex
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int helper(vector<int>& val, vector<int>& wt, int n, int capacity)
{
    // base case
    if(n==0)
    {
        return (capacity/wt[0])*val[0];
    }

    int exclude = 0 + helper(val, wt, n-1, capacity);

    int include = 0;
    if(wt[n]<=capacity)
        include = wt[n] + helper(val, wt, n, capacity-wt[n]);

    return max(include,exclude);
}

int knapSack(vector<int>& val, vector<int>& wt, int capacity)
{
    int n = wt.size();

    return helper(val, wt, n-1, capacity);
}


// memoization
int helper1(vector<int>& val, vector<int>& wt, int n, int capacity, vector<vector<int>> &dp)
{
    // base case
    if(n==0)
    {
        return (capacity/wt[0])*val[0];
    }

    if(dp[n][capacity]!=-1)
        return dp[n][capacity];

    int exclude = 0 + helper1(val, wt, n-1, capacity, dp);

    int include = 0;
    if(wt[n]<=capacity)
        include = wt[n] + helper1(val, wt, n, capacity-wt[n], dp);

    dp[n][capacity] = max(include, exclude);

    return dp[n][capacity];
}

int knapSack1(vector<int>& val, vector<int>& wt, int capacity)
{
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));


    return helper1(val, wt, n-1, capacity, dp);
}


// tabulation
int knapSack2(vector<int>& val, vector<int>& wt, int capacity)
{
    int i=wt.size();

    //Step1:
    vector<vector<int>> dp(i, vector<int>(capacity+1, -1));

    //Step2: base case initialization
    for(int w=0 ; w<=capacity ; w++)
    {
        dp[0][w] = (w/wt[0])*val[0];
    }

    //Step3:
    for(int n=1 ; n<i ; n++)
    {
        for(int cap = 0 ; cap<=capacity ; cap++)
        {
            int exclude = 0 + dp[n-1][cap];

            int include = 0;
            if(wt[n]<=cap)
                include = wt[n] + dp[n][cap-wt[n]];

            dp[n][cap] = max(include, exclude);
        }
    }

    return dp[i-1][capacity];
}

int main()
{
    vector<int> val = {6,1,7,7};
    vector<int> wt = {1,3,4,5};
    int capacity = 8;

    cout << knapSack2(val, wt, capacity) << endl;

    return 0;
}

