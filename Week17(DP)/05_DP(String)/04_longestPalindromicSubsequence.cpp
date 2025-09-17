/* 516

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".


Example 2:
    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".

*/

/*
Appraoch: using the same code and logic of longestCommonSubsequence question
    -- In question longestCommonSubsequence we have two string and we have to find the longest common subsequence between them, 
    -- so if we pay close attention to our current problem, we are asked to find the longest palindromic subsequence, it means that longest subsequence that same from front or back, we can find the answer by finding the longest common subsequence between the given string s and its reverse.

We can also two pointer approach into a single string, one from start and one from end, and check if they are equal or not -> see next solution 
*/

#include<bits/stdc++.h>
using namespace std;


// top-down appraoch
int solveUsingRecursion(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if(i>=a.length()) return 0;
    if(j>=b.length()) return 0;

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

    dp[i][j] = ans;

    return ans;
}

int longestPalindromeSubseq(string s)
{
    string text1 = s; // given string s
    reverse(s.begin(), s.end());
    string text2 = s; // reverse of string s

    int i=0;
    int j=i;

    vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));

    int ans = solveUsingRecursion(text1, text2, i, j, dp);

    return ans;
}

// space optimization
int longestPalindromeSubseq1(string s)
{
    string text1 = s; // given string s
    reverse(s.begin(), s.end());
    string text2 = s; // reverse of string s


    int n = text1.size();
    int m = text2.size();

    vector<int> currCol(n+1, 0);
    vector<int> nextCol(n+1, 0);


    for(int i=m-1 ; i>=0 ; i--)
    {
        for(int j=n-1 ; j>=0 ; j--)
        {
            int ans=0;
            if(text1[j]==text2[i]) 
            {
                ans = 1 + nextCol[j+1];
            }
            else
            { 
                int caseOne = nextCol[j];
                int caseTwo = currCol[j+1];

                ans = 0 + max(caseOne, caseTwo);
            }

            currCol[j] = ans;
        }
        
        nextCol = currCol;
    }

    return nextCol[0];
}

int main()
{
    string s = "abecdeba";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}