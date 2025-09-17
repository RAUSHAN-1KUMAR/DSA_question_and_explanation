/* -> 1143

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.


Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

/*
Appraoch:- DP
    1. top-down approach: TC(n*m)
    2. bottom-up approach -> column wise
    3. space optimization -> column wise
*/

#include<bits/stdc++.h>
using namespace std;


// top-down appraoch
int solveUsingRecursion(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(i>=a.length()) return 0;
    if(j>=b.length()) return 0;

    // STEP3: use the result that is already exist in dp array
    if(dp[i][j] !=-1) return dp[i][j];

    int ans=0;
    if(a[i]==b[j]) 
    {
        ans = 1+solveUsingRecursion(a, b, i+1, j+1, dp);
    }
    else
    { 
        int caseOne = solveUsingRecursion(a, b, i, j+1, dp);
        int caseTwo = solveUsingRecursion(a, b, i+1, j, dp);

        ans = 0 + max(caseOne, caseTwo);
    }

    // STEP2: store the result in dp array
    dp[i][j] = ans;

    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int i=0;
    int j=i;

    // STEP1: create dp array
    vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));

    int ans = solveUsingRecursion(text1, text2, i, j, dp);

    return ans;
}


// bottom-up approach(tabulation method)
int longestCommonSubsequence1(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    // Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // Step2: initialize the dp array using the base case of top down approach
    // initialize the nth row i.e., if i==text1.size();
    for(int col=0 ; col<=m ; col++)
    {
        dp[n][col] = 0;
    }

    // initialize the mth col i.e., if j==text2.size();
    for(int row=0 ; row<=n ; row++)
    {
        dp[row][m] = 0;
    }

    // Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=m-1 ; i>=0 ; i--)// i used as column
    {
        for(int j=n-1 ; j>=0 ; j--)// j used as row
        {  
            int ans=0;
            if(text1[j]==text2[i]) 
            {
                ans = 1 + dp[j+1][i+1];
            }
            else
            { 
                int caseOne = dp[j][i+1];
                int caseTwo = dp[j+1][i];

                ans = 0 + max(caseOne, caseTwo);
            }

            dp[j][i] = ans;
        }
    }

    return dp[0][0];
}


// space optimization
int longestCommonSubsequence2(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    // by using two vector -> 2n space
    vector<int> currCol(n+1, 0);
    vector<int> nextCol(n+1, 0);


    for(int i=m-1 ; i>=0 ; i--)// i used as column
    {
        for(int j=n-1 ; j>=0 ; j--)// j used as row
        {
            int ans=0;
            if(text1[j]==text2[i]) 
            {
                ans = 1 + nextCol[j+1]; //dp[j+1][i+1] -> i+1 matlab nextCol wale array ki baat ho rhi h
            }
            else
            { 
                int caseOne = nextCol[j]; //dp[j][i+1] -> i+1 matlab nextCol wale array ki baat ho rhi h
                int caseTwo = currCol[j+1]; //dp[j+1][i] -> i matlab currCol wale array ki baat ho rhi h

                ans = 0 + max(caseOne, caseTwo);
            }

            currCol[j] = ans; //dp[j][i] -> i matlab currCol wale array ki baat ho rhi h
        }
        
        // shifing
        nextCol = currCol;
    }

    return nextCol[0];
}


int main()
{
    string text1 = "abaaba";
    string text2 = "babbab";

    int ans = longestCommonSubsequence1(text1, text2);

    cout << ans << endl;

    return 0;
}