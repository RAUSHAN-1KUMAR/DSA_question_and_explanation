/* 0/1 knapsack problem -> GFG

Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all [It is not possible to put a part of an item into the bag].

Examples:
    Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
    Output: 3
    Explanation: There are two items which have weight less than or equal to 4. If we select the item with weight 4, the possible profit is 1. And if we select the item with weight 1, the possible profit is 3. So the maximum possible profit is 3. Note that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.


    Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
    Output: 0
*/

/*
Appraoch:- 2D dynamic programming because in this question two parameters are chaging on function call of recursion: one is weight and other is index.

    -- include exclude wala approach
*/

#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;


// recursive solution
int knapSackHelper(int capacity, vector<int> &wt, vector<int> &val, int index)
{
    // base case
    if(index>=val.size()) return 0;
    if(capacity==0) return 0;

    int include = 0;
    if(capacity-wt[index]>=0)
    {
        include = val[index] + knapSackHelper(capacity-wt[index], wt, val, index+1);
    }
    int exclude = 0 + knapSackHelper(capacity, wt, val, index+1);

    return max(include, exclude);
}

int knapSack(int capacity, vector<int> &wt, vector<int> &val)
{
    int index = 0;
    int n=val.size();

    int ans = knapSackHelper(capacity, wt, val, index);

    return ans;
}


// top-down approach
int knapSackHelper1(int capacity, vector<int> &wt, vector<int> &val, int index, vector<vector<int>> &dp)
{
    // base case
    if(index>=val.size()) return 0;
    if(capacity==0) return 0;

    //Step3: use the result that already exist in dp array
    if(dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }

    int include = 0;
    if(capacity-wt[index]>=0){
        include = val[index] + knapSackHelper1(capacity-wt[index], wt, val, index+1, dp);
    }
    int exclude = 0 + knapSackHelper1(capacity, wt, val, index+1, dp);

    //Step2: store the results in dp array
    dp[capacity][index] = max(include, exclude);

    return dp[capacity][index];
}

int knapSack1(int capacity, vector<int> &wt, vector<int> &val)
{
    int index = 0;
    int n=val.size();

    //Step1: Create dp array
    vector<vector<int>> dp(capacity+1, vector<int>(n, -1));

    int ans = knapSackHelper1(capacity, wt, val, index, dp);

    return ans;
}


// bottom-up approach
int knapSackTabulation(int capacity, vector<int> &val, vector<int> &wt)
{
    int n = wt.size();

    // Change1
    vector<vector<int>> dp(n+1, vector<int>(capacity+1,-1));

    // change2: if w==0 return 0
    for(int row=0 ; row<dp.size() ; row++)
    {
        dp[row][0]=0;
    }

    // change3: if i==n return 0
    for(int col=0 ; col<dp[0].size() ; col++)
    {
        dp[n][col]=0;
    }


    for(int index=n-1 ; index>=0 ; index--)
    {
        for(int maxW = capacity ; maxW>=1 ; maxW--)
        {
            int include = 0;
            if(maxW-wt[index]>=0)
            {
                include = val[index] + dp[index+1][maxW-wt[index]];//change4: previously index+1 next col ko bta rha tha ab next row ko bta rha h
            }
            int exclude = 0 + dp[index+1][maxW];

            dp[index][maxW] = max(include, exclude);       
        }
    }

    return dp[0][capacity];
}


// more space optimization
int knapSackSpaceOpti(int capacity, vector<int> &val, vector<int> &wt)
{
    int n = wt.size();

    vector<int> oneArray(capacity+1, 0);

    for(int index=n-1 ; index>=0 ; index--)
    {
        for(int cap=capacity ; cap>=1 ; cap--)
        {
            int include = 0;
            if(cap >= wt[index])
                include = val[index] + oneArray[cap-wt[index]];

            int exclude = 0 + oneArray[cap];

            oneArray[cap] = max(include, exclude);
        }
    }

    return oneArray[capacity];
}


int main()
{
    vector<int> wt = {3,2,1};
    vector<int> val = {1,2,3};
    int W = 4;

    cout << knapSack(W, wt, val) << endl;

    return 0;
}





