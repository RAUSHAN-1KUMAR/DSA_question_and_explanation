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
Appraoch: 
    - We can also two pointer approach into a single string, one from start and one from end, and check if they are equal or not. If they are equal, we can increase the count+2 and move both pointers towards the center. If they are not equal, we can move one pointer at a time and check again.
*/

#include<bits/stdc++.h>
using namespace std;


// top-down appraoch
int solveUsingRecursion(string &a, int i, int j, int &n, vector<vector<int>> &dp)
{
    if(i==j)
        return 1;
    if(i>j)
        return 0;

    if(dp[i][j]!=-1)    
        return dp[i][j];

    int ans=0;
    if(a[i]==a[j]){
        int ans = 2 + solveUsingRecursion(a, i+1, j-1, n, dp);
    }
    else{
        int caseA = solveUsingRecursion(a, i, j-1 , n, dp);
        int caseB = solveUsingRecursion(a, i+1, j, n, dp);

        ans = max(caseA, caseB);
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int longestPalindromeSubseq(string s)
{
    int n=s.size();
    string text1 = s; // given string s

    int i=0;
    int j=n-1;

    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

    int ans = solveUsingRecursion(text1, i, j, n, dp);

    return ans;
}

int main()
{
    string s = "abecdeba";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}