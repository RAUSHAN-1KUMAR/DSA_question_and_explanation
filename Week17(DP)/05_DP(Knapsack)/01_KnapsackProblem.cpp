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

void print(vector<vector<int>> &dp);

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
    if(capacity-wt[index]>=0)
    {
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
int knapSackTabulation(int capacity, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();

    // Step1: create dp array
    vector<vector<int>> dp(capacity+1, vector<int>(n+1,-1));

    // Step2: initialize the dp array using base case of top-down approach
    // initializing the 0th row i.e., if W=0
    for(int col=0 ; col<dp[0].size() ; col++)
    {
        dp[0][col]=0;
    }

    // initializing the out of bound case, nth column i.e., if index==n;
    for(int row=0 ; row<dp.size() ; row++)
    {
        dp[row][n]=0;
    }

    // Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int index=n-1 ; index>=0 ; index--) // index used as column
    {
        for(int maxW = capacity ; maxW>=1 ; maxW--) // maxW used as row
        {
            int include = 0;
            if(maxW-wt[index]>=0)
            {
                include = val[index] + dp[maxW-wt[index]][index+1];
            }
            int exclude = 0 + dp[maxW][index+1];

            dp[maxW][index] = max(include, exclude);       
        }
    }

    return dp[capacity][0];
}


// spaceOptimization
int knapSackSpaceOptm(int capicity, vector<int> &wt, vector<int> &val)
{
    int n = val.size();

    vector<int> nextCol(capicity+1, -1); // the index+1 wala array, ham jo her call p index+1 ker rhe the bottom-up approach ke for loop m

    vector<int> currCol(capicity+1, -1); // ye wo array h jo, next ko shift krega(next = curr), next walle value ke liye, index+1 array 

    for(int row=0 ; row<=capicity ; row++)
    {
        nextCol[row]=0;
    }


    // take the same logic of bottom-up approach, just time modify the dp array into next/curr array
    for(int index=n-1 ; index>=0 ; index--)
    {
        for(int w=capicity ; w>=0 ; w--)
        {
            int include = 0;
            if(w-wt[index]>=0)
            {
                include = val[index] + nextCol[w-wt[index]]; //dp[w-wt[index]][index+1] -> index+1 matlab nextCol wale array ki baat ho rhi h
            }

            int exclude = 0 + nextCol[w]; // dp[w][index+1] -> index+1 matlab nextCol wale array ki baat ho rhi h

            currCol[w] = max(include, exclude); // dp[w][index] -> index matlab currCol wale array ki baat ho rhi h
        }

        //shift
        nextCol = currCol;
    }

    return currCol[capicity];
}


// MoreSpaceOptimized
int knapSackMoreOPtm(int capacity, vector<int> &wt, vector<int> &val)
{
    int n = val.size();

    // ek hi array use krengen and then modigy bhi kerte jayengen next index ke liye
    vector<int> next(capacity+1, 0);

    // take the same logic of bottom-up approach, just time modify the dp array into next array
    for(int index=n-1 ; index>=0 ; index--)
    {
        // Change:- capacity->0 ja rhe h
        for(int w=capacity ; w>=0 ; w--)
        {
            int include = 0;
            if(wt[index]<=w)
            {
                include = val[index] + next[w-wt[index]];
            }

            int exclude = 0 + next[w];

            next[w] = max(include, exclude);
        }
    }

    return next[capacity];

}


int main()
{
    vector<int> wt = {3,2,1};
    vector<int> val = {1,2,3};
    int W = 4;

    cout << knapSackTabulation(W, wt, val) << endl;

    return 0;
}

void print(vector<vector<int>> &dp)
{
    for(auto vec:dp)
    {
        for(auto num:vec)
        {
            if(num != -1) cout << " " << num << " ";
            else cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}





