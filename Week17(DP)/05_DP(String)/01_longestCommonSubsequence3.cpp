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
Appraoch:-
    -- bottom up approach -> row wise
    -- space optimization -> row wise
*/

#include<bits/stdc++.h>
using namespace std;


// bottom-up approach(tabulation method)
int longestCommonSubsequence1(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    string a=text1;
    string b=text2;

    vector<vector<int>> dp(n+1 , vector<int> (m+1,-1));

    // if i>=n return 0
    for(int col=0 ; col<=m ; col++)
    {
        dp[n][col]=0;
    }

    // if j>=m return 0
    for(int row=0 ; row<=n ; row++)
    {
        dp[row][m]=0;
    }

    for(int i=n-1 ; i>=0 ; i--)//-> i used as row
    {
        for(int j=m-1 ; j>=0 ; j--) //-> j used as col
        {
            int ans=0;
            if(a[i]==b[j]) 
            {
                ans = 1+dp[i+1][j+1];
            }
            else
            { 
                int caseOne = dp[i][j+1];
                int caseTwo = dp[i+1][j];

                ans = 0 + max(caseOne, caseTwo);
            }

            // STEP2: store the result in dp array
            dp[i][j] = ans; 
        }
    }

    for(auto vec:dp){
        for(auto num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return dp[0][0];
}


// space optimization
int longestCommonSubsequence2(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    string a=text1;
    string b=text2;

    vector<int> currRow(m+1, 0);
    vector<int> nextRow(m+1, 0);

    for(int i=n-1 ; i>=0 ; i--)//-> i used as row
    {
        for(int j=m-1 ; j>=0 ; j--) //-> j used as col
        {
            int ans=0;
            if(a[i]==b[j]) 
            {
                ans = 1+nextRow[j+1]; // dp[i+1][j+1] -> i+1 matlab nextRow wale array ki baat ho rhi h
            }
            else
            { 
                int caseOne = currRow[j+1]; // dp[i][j+1] -> i matlab currRow ki baat ho rhi h
                int caseTwo = nextRow[j]; // dp[i+1][j] -> i+1 matlab nextRow ki baat ho rhi h

                ans = 0 + max(caseOne, caseTwo);
            }

            // STEP2: store the result in dp array
            currRow[j] = ans; // dp[i][j] -> i matlab currRow ki baat ho rhi h
        }

        nextRow = currRow;
    }

    return nextRow[0];
}


int main()
{
    string text1 = "abaaba";
    string text2 = "babbab";

    int ans = longestCommonSubsequence1(text1, text2);

    cout << ans << endl;

    return 0;
}

