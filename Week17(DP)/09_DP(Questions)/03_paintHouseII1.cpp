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
Approach:- optimised code
    -- how can we optimise it,, 
    -- Okk so lets think about it,, 
        i) can we replace index i? -> no, because that is the main index that represents houses, 
        ii) can we replace color choice at each index-> no, because we have to go through each color choice
        iii) OKK so now, can we replace prev index-> yes, why we are going through all the prev index but if we can calculate the last index most and second most minimum value then we can solve it using two variable only and the TC will be O(n*k*2)

    code is also little bit different from previous one, -> What we are doing ??
        - first we will color the house zero with all its color and the store the first and second minCost into two variable 
        - the we start our loop from house 1, and color the house 1 with all color by adding the min of previous row/house min color cost, and then again for current row/house we are gonna update those two variable-> first and second minCost
        - the goes till end and at the end we return the last row minCost, from the dp 

    IMP-> remember the logic to find the least and second least number

TC-> O(n*k)
*/

#include<bits/stdc++.h>
using namespace std;

// tabulation 
int distinctColoring2(vector<vector<int>> &colors)
{
    int i=0;
    int N=colors.size();
    int K=colors[0].size();

    vector<vector<int>> dp(N+1, vector<int>(K, -1));

    int firstMin=INT_MAX;
    int secondMin=INT_MAX;

    // first house 0
    for(int clr=0;clr<K;clr++)
    {
        dp[0][clr]=colors[0][clr];

        if(dp[0][clr]<=firstMin){
            secondMin = firstMin;
            firstMin = dp[0][clr];
        }   
        else if(dp[0][clr]<=secondMin)
            secondMin = dp[0][clr];
    }

    // now rest of the house i.e., from index 1
    for(int i=1 ; i<N ; i++)
    {
        int newFirstMin=INT_MAX;
        int newSecondMin=INT_MAX;
        for(int clr=0;clr<K;clr++)
        {
            if(firstMin==dp[i-1][clr]){
                dp[i][clr]=secondMin + colors[i][clr];
            }
            else{
                dp[i][clr]=firstMin + colors[i][clr];
            }

            if(dp[i][clr]<=newFirstMin){
                newSecondMin=newFirstMin;
                newFirstMin=dp[i][clr];
            }
            else if(dp[i][clr]<=newSecondMin){
                newSecondMin=dp[i][clr];
            }
        }

        firstMin=newFirstMin;
        secondMin=newSecondMin;
    }

    return firstMin;
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

