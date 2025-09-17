/* -> 265

Ninja has started a painting business recently. He got a contract to paint ‘N’ houses in a city. Ninja has ‘K’ colors to choose from. But the client has a condition that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an N x K cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on.

Your task is to help Ninja to find the minimum cost required to paint houses according to this condition.

For Example :
Let say N = 2 and K = 3 and costs = [ [1,5,3] , [2,9,4] ] 

In this case,
Ninja can paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5 .
Note :

Assume 0 based indexing
*/

/*
Approach:- 
    -- at every index/house, we have K choices so explore all these K choices but also look for the prev_index/color
        K-> colors[0].size() i.e., no. of columns

    1. recursive solutin
    2. memoization: TC-> O(n*k*k) SC:(n*k)

    can we do it with TC-> O(n*k) only?? next solution
*/

#include<bits/stdc++.h>
using namespace std;

// recursive
int helper(int &N, vector<vector<int>> &colors, int i, int prev)
{
    if(i>=N) return 0;

    int ans=INT_MAX;
    for(int clr=0;clr<colors[0].size();clr++)
    {
        if(prev==-1 || clr!=prev){
            ans = min(ans, (int)(colors[i][clr]+helper(N, colors, i+1, clr)));
        }
    }

    return ans;
}

int distinctColoring(vector<vector<int>> &colors)
{
    int i=0;
    int prev=-1;
    int N=colors.size();
    return helper(N, colors, i, prev);
}


// memoization
int helper1(int &N, vector<vector<int>> &colors, int i, int prev, unordered_map<int, unordered_map<int, int>> &dpMemo)
{
    if(i>=N) return 0;

    if(dpMemo.count(i) && dpMemo[i].count(prev)){
        return dpMemo[i][prev];
    }

    int ans=INT_MAX;
    for(int clr=0;clr<colors[0].size();clr++)
    {
        if(prev==-1 || clr!=prev){
            ans = min(ans, (int)(colors[i][clr]+helper1(N, colors, i+1, clr, dpMemo)));
        }
    }

    dpMemo[i][prev] = ans;

    return dpMemo[i][prev];
}

int distinctColoring1(vector<vector<int>> &colors)
{
    int i=0;
    int prev=-1;
    int N=colors.size();

    unordered_map<int, unordered_map<int, int>> dpMemo;

    return helper1(N, colors, i, prev, dpMemo);
}


// tabulation 
int distinctColoring2(vector<vector<int>> &colors)
{
    int i=0;
    int N=colors.size();
    int M=colors[0].size();

    unordered_map<int, unordered_map<int, int>> dpMemo;

    // base case: if(i>=N) return 0;
    for(int p=0 ; p<=M ; p++){
        dpMemo[N][p] = 0;
    }

    for(int i=N-1 ; i>=0 ; i--)// house num
    {
        for(int prev=-1; prev < M ; prev++)//prev color number
        {
            int ans=INT_MAX;
            for(int clr=0;clr<M;clr++)// avlb color number
            {
                if(prev==-1 || clr!=prev){
                    ans = min(ans, (int)(colors[i][clr]+dpMemo[i+1][clr]));
                }
            }

            dpMemo[i][prev] = ans;
        }
    }

    return dpMemo[0][-1];
}

int main()
{
    vector<vector<int>> colors={
        {1,5,7,2,1,4},
        {5,8,4,3,6,1},  
        {3,2,9,4,2,3}, 
        {1,2,4,9,1,7} 
    };
    cout << distinctColoring2(colors) << endl;
    return 0;
}

