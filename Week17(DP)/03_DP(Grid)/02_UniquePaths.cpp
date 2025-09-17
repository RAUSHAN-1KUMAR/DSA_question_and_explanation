/* -> 62

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

 

Example 1:
    Input: m = 3, n = 7
    Output: 28


Example 2:
    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
*/

/*
Approach:-
    1. Recursive solution:-
        -- at every position we have two choice, either we go right or down.
        -- So at every position move to both position

        TC:- O(2^(m+n)): we are not just going down like previous question, we are also going right. So total unique states = m*n, but the depth of the recursive call depends on (m+n), so that's why TC = O(2^(m+n))
            -- TC = 2^m.2^n => (forEachRow.forEachCOl), because call also goes to right i.e, column

        SC:- O(m+n) -> stack space

    2. Top-down approach (memoization)
        TC:- O(m*n)
        SC:- O(m+n)+O(m*n)

    3. Bottom-up approach (tabulation)
        TC:- O(m*n)
        SC:- O(m*n)

    4. Space optimzation
        TC:- O(m*n)
        SC:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void dpArrayPrint(vector<vector<int>>& dp)
{
    for(auto vec:dp)
    {
        for(auto num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}


// recursive solution
int helper(int &m, int &n, int row, int col)
{
    // base cases
    if(row==m-1 && col==n-1)
        return 1;

    if(row>=m || col>=n)
        return 0;

    // move right and left
    int rightMov = helper(m,n, row, col+1);
    int downMov = helper(m,n,row+1,col);

    return rightMov+downMov;
}

int uniquePaths(int m, int n)
{
    int i=0;
    int j=0;
    
    return helper(m,n,i,j);
}


// Memoization
int helper1(int &m, int &n, int row, int col, vector<vector<int>> &dp)
{
    if(row==m-1 && col==n-1)
        return 1;
    if(row>=m || col>=n)
        return 0;

    //Step3:
    if(dp[row][col]!=-1)
        return dp[row][col];


    int rightMov = helper1(m,n, row, col+1, dp);
    int downMov = helper1(m,n,row+1,col, dp);

    //Step2:
    dp[row][col]=rightMov+downMov;

    return dp[row][col];
}

int uniquePaths1(int m, int n)
{
    int i=0;
    int j=0;

    // Step1:
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    return helper1(m,n,i,j,dp);
}


// Tabulation Method
int uniquePaths2(int m, int n)
{
    // Step1:
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Step2: if(row==m-1 && col==n-1) return 1;
    dp[m-1][n-1]=1;

    //Step3
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=n-1 ; col>=0 ; col--)
        {
            if(row==m-1 && col==n-1) // catch condition
                continue;

            int rightMov = dp[row][col+1];
            int downMov = dp[row+1][col];

            dp[row][col]=rightMov+downMov;
        }
    }

    dpArrayPrint(dp);

    return dp[0][0];
}


// space optimization
int uniquePaths3(int m, int n)
{
    // Step1:
    vector<int> singleArray(n+1,0);

    //Step2:
    singleArray[n-1]=1;

    //Step3
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=n-1 ; col>=0 ; col--)
        {
            if(row==n-1 && col==n-1) // catch condition
                continue;

            int rightMov = singleArray[col+1];
            int downMov = singleArray[col];

            singleArray[col]=rightMov+downMov;
        }
    }

    //printing array
    for(int num:singleArray)
        cout << num << " ";
    cout << endl;

    return singleArray[0];
}

int main()
{
    int m=3;
    int n=3;

    cout << uniquePaths2(m,n) << endl;

    return 0;
}