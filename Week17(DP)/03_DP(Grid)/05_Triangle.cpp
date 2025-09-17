/* -> 120

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are at index j in row i, then you move to i+1 index in j or j+1 in each step.

 

Example 1:
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
       2
      3 4
     6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


Example 2:
    Input: triangle = [[-10]]
    Output: -10
*/

/*
Approach:-
    -- Question is similar to geek's training, i.e., the condition here is that, if the prev is i, then for next row, either i can choose prev or prev+1 element only..
    -- so can see that there would be only two call for each recursive call, for prev and prev+1

    1. Recursive method:- 
        TC:- O(2^(rows) x rows): the 2nd rows stands for prev, and it may exceeds to no. of rows, prev power m issiliye nhi gya kyunki depth or recursive call depended only on number of rows

        But the actual answer TC is:- O(2^rows) only, 
            - becuase we are calling two calls independent of prev. prev is just to make two calls only. prev is depentent/intrinsic to the current row, we can't separate prev as fixed multiplier because it is already accounted for the recursive branching(2^rows)

            - Understanding whether a variable is independent or intrinsic to the recursion process is key to analyzing time complexity accurately

        SC:- O(rows) -> stack space

    2. Memoization
        TC:- O(rows^2)
        SC:- O(rows) + O(rows^2)

    3. Tabulation
        TC:- O(rows^2)
        SC:- O(rows^2)

    4. Space Optimization
        TC:- O(rows^2)
        SC:- o(rows)

One more recursive logic is there-> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// Recursice method
int helper(vector<vector<int>> &triangle, int &m, int row, int prev)
{
    // base case
    if(row>=m) return 0;

    // calculating maxIndex, so that prev+1 should not exceed the col limit
    int maxIndex=triangle[row].size();

    // i can only use prev index element
    int caseA = triangle[row][prev] + helper(triangle, m, row+1, prev);

    // or i can use prev+1 index element
    int caseB = INT_MAX;
    if(prev+1<maxIndex)
        caseB = triangle[row][prev+1] + helper(triangle, m, row+1, prev+1);

    return min(caseA, caseB);
}

int minimumTotal(vector<vector<int>>& triangle)
{
    int row=0;
    int prev=0;
    int m=triangle.size();

    return helper(triangle, m, row, prev);
}


// top-down approach
int helper1(vector<vector<int>> &triangle, int &m, int row, int prev, vector<vector<int>> &dp)
{
    if(row>=m) return 0;

    //Step3:
    if(dp[row][prev]!=-1)
        return dp[row][prev];

    int maxIndex=triangle[row].size();
    int caseA = triangle[row][prev] + helper1(triangle, m, row+1, prev, dp);
    int caseB = INT_MAX;
    if(prev+1<maxIndex)
        caseB = triangle[row][prev+1] + helper1(triangle, m, row+1, prev+1, dp);

    //Step2:
    dp[row][prev] = min(caseA, caseB);

    return dp[row][prev];
}

int minimumTotal1(vector<vector<int>>& triangle)
{
    int row=0;
    int prev=0;
    int m=triangle.size();

    //Step1;
    vector<vector<int>> dp(m, vector<int>(m, -1));

    return helper1(triangle, m, row, prev, dp);
}


// tabulation method
int minimumTotal2(vector<vector<int>>& triangle)
{
    int m=triangle.size();

    //Step1;
    vector<vector<int>> dp(m+1, vector<int>(m, -1));

    //Step2: if(row>=m) return 0;
    for(int col=0 ; col<m ; col++)
        dp[m][col]=0;

    //Step3:
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int prev=row ; prev>=0 ; prev--)
        {
            int maxIndex=triangle[row].size();

            int caseA = triangle[row][prev] + dp[row+1][prev];

            int caseB = INT_MAX;
            if(prev+1<maxIndex)
                caseB = triangle[row][prev+1] + dp[row+1][prev+1];

            dp[row][prev] = min(caseA, caseB);
        }
    }

    return dp[0][0];
}


// space optimization
int minimumTotal3(vector<vector<int>>& triangle)
{
    int m=triangle.size();

    //Step1 and Step2
    vector<int> singleArray(m+1, 0);

    //Step3:
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int prev=0 ; prev<=row ; prev++)
        {
            int maxIndex=triangle[row].size();

            int caseA = triangle[row][prev] + singleArray[prev];

            int caseB = INT_MAX;
            if(prev+1<maxIndex)
                caseB = triangle[row][prev+1] + singleArray[prev+1];

            singleArray[prev] = min(caseA, caseB);
        }
    }

    return singleArray[0];
}


int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << minimumTotal3(triangle) << endl;

    return 0;
}



