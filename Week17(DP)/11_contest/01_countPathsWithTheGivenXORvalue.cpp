/* -> 3393

You are given a 2D integer array grid with size m x n. You are also given an integer k.

Your task is to calculate the number of paths you can take from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) satisfying the following constraints:
    - You can either move to the right or down. Formally, from the cell (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) if the target cell exists.
    - The XOR of all the numbers on the path must be equal to k.

RETURN the total number of such paths.

Since the answer can be very large, return the result modulo 10^9 + 7.

 

Example 1:
    Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11
    Output: 3
    Explanation: 
    The 3 paths are:
    (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
    (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
    (0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)


Example 2:
    Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2
    Output: 5
    Explanation:
    The 5 paths are:
    (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
    (0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
    (0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
    (0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
    (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)


Example 3:
    Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10
    Output: 0


Constraints:
    - 1 <= m == grid.length <= 300
    - 1 <= n == grid[r].length <= 300
    - 0 <= grid[r][c] < 16
    - 0 <= k < 16
*/

/*
Approach:- 3D DP
    -- So iss question m ham kha pe phase,, 
        i) -> i got memory limit exceeded, that's because i just took the random size of, dp[][][zth], zth position. Because i was confused about the zth maximum possible value, becuase we are doing XOR of each element, if it was sum them i could predict the maximum zth value

        ii) mai mod nhi le rha tha,, mod lena chahiye tha her operations m

    -- so how we can predict the maximum XOR value -> as we can see in the constraint that 0<=grid[i][j]<16. SO, it means there will always be a 4bit number, so if its 4th bit then maximum possible XOR will be (1111) = 15

Ye chiz samjhna bhut zarurui hai:-(mainly for tabulation method)
    - dp[row][col][ele] => tells numbers of ways from cell (row,col) to the bottom-right (n-1, m-1) such that the XOR of all numbers along the path is exactly ele.
    - so initially i was passing row->0 col->0 ele->0, it means i was finding no. of ways from cell (0,0) to the bottom-right (n-1, m-1) such that the XOR of all numbers along the path is exactly 0. but they said to find the path for k yeah so if at last ele^grid[n-1][m-1]==k then it means our path is correct, 
        - HOW-> kyunki ab ager isko (ele^grid[n-1][m-1])^k kre to iska value zero ho jayega if and only if ele^grid[n-1][m-1]==k
*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

// recursive solution
int helper(vector<vector<int>>& grid, int row, int col, int ele, int &n, int &m, int &k)
{
    if(row==n-1 && col==m-1)
    {
        if(k==(ele^grid[row][col])) return 1;
        return 0;
    }

    int right = 0;
    if(col+1 < m)
        right = helper(grid, row, col+1, ele^grid[row][col], n, m, k) % mod;
    
    int down = 0;
    if(row+1 < n)
        down = helper(grid, row+1, col, ele^grid[row][col], n, m, k) % mod;

    return (right+down) % mod;
}

int countPathsWithXorValue(vector<vector<int>>& grid, int k)
{
    int n=grid.size();
    int m=grid[0].size();
    

    int i=0;
    int j=0;
    int ele = 0;

    return helper(grid, i, j, ele, n, m, k);
}


// memoization
int helper1(vector<vector<int>>& grid, int row, int col, int ele, int &n, int &m, int &k, vector<vector<vector<int>>> &dp)
{
    if(row==n-1 && col==m-1)
    {
        if(k==(ele^grid[row][col])) return 1;
        return 0;
    }

    //Step3:
    if(dp[row][col][ele]!=-1)
            return dp[row][col][ele];


    int right = 0;
    if(col+1 < m)
        right = helper1(grid, row, col+1, ele^grid[row][col], n, m, k, dp) % mod;
    
    int down = 0;
    if(row+1 < n)
        down = helper1(grid, row+1, col, ele^grid[row][col], n, m, k, dp) % mod;

    //Step2:
    dp[row][col][ele]=(right+down) % mod;

    return dp[row][col][ele];
}

int countPathsWithXorValue1(vector<vector<int>>& grid, int k)
{
    int n=grid.size();
    int m=grid[0].size();
    

    int i=0;
    int j=0;
    int ele = 0;

    //Step1:
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (16, -1)));//-> total 16 tak hi jayega

    return helper1(grid, i, j, ele, n, m, k, dp) % mod;
}


//tabulation
int countPathsWithXorValue2(vector<vector<int>>& grid, int k)
{
    int n=grid.size();
    int m=grid[0].size();
    

    int i=0;
    int j=0;
    int ele = 0;

    //Step1:
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int> (16, 0)));//-> total 16 tak hi jayega

    //Step2: initialization
    // observe carefully how the base case is initialized here
    dp[n-1][m-1][k^grid[n-1][m-1]] = 1;

    //Step3:
    for(int row=n-1 ; row>=0 ; row--)
    {
        for(int col=m-1 ; col>=0; col--)
        {
            
            for(int ele=15 ; ele>=0 ; ele--)
            {
                if(row==n-1 && col==m-1)
                    continue;

                int right = 0;
                if(col+1 != m)
                    right = dp[row][col+1][ele^grid[row][col]];
                
                int down = 0;
                if(row+1 != n)
                    down = dp[row+1][col][ele^grid[row][col]];

                //Step2:
                dp[row][col][ele]=(right+down) % mod;
            }
        }
    }

    return dp[0][0][0];
}

int main()
{
    vector<vector<int>> grid = {
        {8,13,6,5,3,0,12,7,2,0},
        {14,13,0,1,10,8,8,9,15,12},
        {5,15,7,7,7,11,3,1,7,14},
        {8,3,2,14,1,5,3,5,6,4},
        {12,9,1,1,0,10,0,4,1,12},
        {9,6,10,9,3,14,2,10,0,1},
        {9,13,2,8,5,5,10,6,8,2},
        {15,13,10,6,15,9,15,14,3,13},
        {11,7,4,13,6,4,4,0,6,1}
    };

    int k=9;
    cout <<countPathsWithXorValue(grid, k) << endl;

    return 0;
}