/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.


Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".


Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/

/*
Approach;-
    -- at each index i have options like
        i) if characters are same then don't delete
        ii) if characters are not same then either delete form string s1 or from string s2

        Question is similar to 'longest common subsequence', we just have to handle the base case carefully

A easy and smooth approach:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// recursion
int helper(string &w1, string &w2, int i, int j)
{
    // base cases
    if(i>=w1.size()&&j>=w2.size()) 
        return 0;
    else if(i>=w1.size())
        return w2.size()-j;
    else if(j>=w2.size())
        return w1.size()-i;

    int ans = 0;
    if(w1[i]==w2[j])
        ans = helper(w1, w2, i+1, j+1);
    else
    {
        ans = 1 + min(helper(w1, w2, i+1, j), helper(w1, w2, i, j+1));
    }

    return ans;
}   

int minDistance(string word1, string word2)
{
    int i=0, j=0;

    return helper(word1, word2, i, j);
}


// memoization
int helper1(string &w1, string &w2, int i, int j, vector<vector<int>> &dp)
{
    // base cases
    if(i>=w1.size()&&j>=w2.size()) 
        return 0;
    else if(i>=w1.size())
        return w2.size()-j;
    else if(j>=w2.size())
        return w1.size()-i;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = 0;
    if(w1[i]==w2[j])
        ans = helper1(w1, w2, i+1, j+1, dp);
    else
    {
        ans = 1 + min(helper1(w1, w2, i+1, j, dp), helper1(w1, w2, i, j+1, dp));
    }

    dp[i][j] = ans;

    return dp[i][j];
}   

int minDistance1(string word1, string word2)
{
    int i=0, j=0;

    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

    return helper1(word1, word2, i, j, dp);
}


int main()
{
    string word1 = "sea";
    string word2 = "eat";

    cout << minDistance(word1, word2) << endl;

    return 0;
}


