/* -> 256

There is a row of N houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color. Find the minimum cost to paint all houses.

The cost of painting each house in red, blue or green colour is given in the array r[], g[] and b[] respectively.


Example 1:
    Input:
    N = 3
    r[] = {1, 1, 1}
    g[] = {2, 2, 2}
    b[] = {3, 3, 3}
    Output: 4
    Explanation: We can color the houses 
    in RGR manner to incur minimum cost.
    We could have obtained a cost of 3 if 
    we coloured all houses red, but we 
    cannot color adjacent houses with 
    the same color.


Example 2:
    Input:
    N = 3
    r[] = {2, 1, 3}
    g[] = {3, 2, 1}
    b[] = {1, 3, 2} 
    Output: 3
    Explanation: We can color the houses
    in BRG manner to incur minimum cost.
*/

/*
Approach:- 
    -- at every index/house, we have three choices red, green or blue so explore all these three choices but also look for the prev_index/color
*/

#include<bits/stdc++.h>
using namespace std;

long long int helper(int &N, int r[], int g[], int b[], int i, int prev, unordered_map<int, unordered_map<int,long long>> &dp)
{
    if(i>=N) return 0;

    if(dp.count(i) && dp[i].count(prev)){
        return dp[i][prev];
    }

    long long ans=LONG_LONG_MAX;
    for(int p=1 ; p<=3 ; p++){
        if(prev==-1 || p!=prev){
            if(p==1){
                ans = min(ans, (long long)(r[i]+helper(N, r, g, b, i+1, p, dp)));
            }
            else if(p==2){
                ans = min(ans, (long long)(g[i]+helper(N, r, g, b, i+1, p, dp)));
            }
            else{
                ans = min(ans, (long long)(b[i]+helper(N, r, g, b, i+1, p, dp)));
            }
        }
    }

    dp[i][prev] = ans;

    return dp[i][prev];
}

long long int distinctColoring(int N, int r[], int g[], int b[])
{
    int i=0;
    int prev=-1;

    // if i use vector then i also have to manage the shifting of prev index, as it can be negative -> -1
    unordered_map<int, unordered_map<int,long long>> dp;// to store the {i, prev}

    return helper(N, r, g, b, i, prev, dp);
}


int main()
{
    int N=3;
    int r[]={1,1,1};
    int g[]={2,2,2};
    int b[]={3,3,3};
    cout << distinctColoring(N, r, g, b) << endl;
    return 0;
}




