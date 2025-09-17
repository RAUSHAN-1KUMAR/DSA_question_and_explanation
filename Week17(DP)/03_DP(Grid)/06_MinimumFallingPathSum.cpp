/* -> 931

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.


Example 2:
    Input: matrix = [[-19,57],[-40,-5]]
    Output: -59
    Explanation: The falling path with a minimum sum is shown.
*/

/*
Appraoch:-
    -- we can solve this question using the previously done logics, like we did in previous question(Triangle with two different apporaches)
        1. we choose the index on the basis of prev index used
        2. or call all possible direction at every index, i.e., oneDown, oneLeftDiag, oneRightDiag

    -- I solved it using 2nd logic, but after memoization it still gives TLE
    -- Approach was good, so indeed tabulation don't give TLE

TC:- O(3^(m) x n) :m->no. of rows, and n->no.of cols, but the actual answer is O(3^m) only becuase:-
    - cols is simply the number of starting points (when calculating the minimum from all possible first-row columns). However, during recursion, each column does not multiply the recursion tree—it is already accounted for as part of the branching factor.

    - The 3^rows accounts for the branching in the recursion tree, where each state branches into 3 calls for each row.

    - Multiplying by cols would double-count states because the branching process already covers all possibilities for columns.

For memoization:- it would be: O(rows x cols)
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
    cout << endl;
}


// Recursice method (using 2nd approach)
int helper(vector<vector<int>> &matrix, int &m, int &n, int row, int col)
{
    // base case
    if(row>=m) return 0;


    int oneDown = matrix[row][col] + helper(matrix, m, n, row+1, col);

    int oneLeftDiag = INT_MAX;
    if(col-1>=0)
        oneLeftDiag = matrix[row][col] + helper(matrix, m, n, row+1, col-1);

    int oneRightDiag = INT_MAX;
    if(col+1<n)
        oneRightDiag = matrix[row][col] + helper(matrix, m, n, row+1, col+1);

    return min(oneDown, min(oneLeftDiag, oneRightDiag));
}


int minFallingPathSum(vector<vector<int>>& matrix)
{
    int row=0;
    int col=0; 
    int m=matrix.size();
    int n=matrix[0].size();

    // calling helper function for every top row elements, as at every index we are only making three calls, but for the first row we have to go through all the elements
    int ans=INT_MAX;
    for(int i=0 ; i<n ; i++) 
    {
        int callAT = helper(matrix, m, n, row, i);

        ans = min(ans, callAT);
    }

    return ans;
}



// Top-down approach
int helper1(vector<vector<int>> &matrix, int &m, int &n, int row, int col, vector<vector<int>> &dp)
{
    // base case
    if(row>=m) return 0;

    //Step3:
    if(dp[row][col]!=-1)
        return dp[row][col];


    int oneDown = matrix[row][col] + helper1(matrix, m, n, row+1, col, dp);

    int oneLeftDiag = INT_MAX;
    if(col-1>=0)
        oneLeftDiag = matrix[row][col] + helper1(matrix, m, n, row+1, col-1, dp);

    int oneRightDiag = INT_MAX;
    if(col+1<n)
        oneRightDiag = matrix[row][col] + helper1(matrix, m, n, row+1, col+1, dp);

    //Step2:
    dp[row][col] = min(oneDown, min(oneLeftDiag, oneRightDiag));

    return dp[row][col];
}

int minFallingPathSum1(vector<vector<int>>& matrix)
{
    int row=0;
    int m=matrix.size();
    int n=matrix[0].size();

    //Step1:
    vector<vector<int>> dp(m, vector<int>(n,-1));

    int ans=INT_MAX;
    for(int col=0 ; col<n ; col++)
    {
        int callAT = helper1(matrix, m, n, row, col, dp);

        ans = min(ans, callAT);
    }

    return ans;
}


// Tabulation method
int minFallingPathSum2(vector<vector<int>>& matrix)
{
    int row=0;
    int m=matrix.size();
    int n=matrix[0].size();

    //Step1:
    vector<vector<int>> dp(m+1, vector<int>(n,-1));

    //Step2: if(row>=m) return 0;
    for(int col=0 ; col<n ; col++)
        dp[m][col]=0;

    //Step3:
    int ans=INT_MAX;

    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=n-1 ; col>=0 ; col--)
        {
            int oneDown = matrix[row][col] + dp[row+1][col];

            int oneLeftDiag = INT_MAX;
            if(col-1>=0)
                oneLeftDiag = matrix[row][col] + dp[row+1][col-1];

            int oneRightDiag = INT_MAX;
            if(col+1<n)
                oneRightDiag = matrix[row][col] + dp[row+1][col+1];

            dp[row][col] = min(oneDown, min(oneLeftDiag, oneRightDiag));

            // catch case
            if(row==0)
                ans = min(ans,dp[row][col]);
        }
    }

    return ans;
}


// Space optimization using two array
int minFallingPathSum3(vector<vector<int>>& matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();

    //Step1:
    vector<int> currArray(n,0);
    vector<int> nextArray(n,0); //Step2: initialized it


    //Step3:
    int ans=INT_MAX;
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=n-1 ; col>=0 ; col--)
        {
            int oneDown = matrix[row][col] + nextArray[col];

            int oneLeftDiag = INT_MAX;
            if(col-1>=0)
                oneLeftDiag = matrix[row][col] + nextArray[col-1];

            int oneRightDiag = INT_MAX;
            if(col+1<n)
                oneRightDiag = matrix[row][col] + nextArray[col+1];

            currArray[col] = min(oneDown, min(oneLeftDiag, oneRightDiag));

            if(row==0)
                ans = min(ans,currArray[col]);
        }

        // shifting
        nextArray=currArray;
    }

    return ans;
}



int main()
{
    vector<vector<int>> matrix = {
        {2,1,3,6},
        {6,5,4,1},
        {7,1,8,9},
        {2,4,5,1}
    };

    cout << minFallingPathSum3(matrix) << endl;

    return 0;
}

