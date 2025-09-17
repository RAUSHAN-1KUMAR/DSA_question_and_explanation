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
    -- What can be the maximum possible operation to make string equal -> remove all characters from s1 + insert all characters of s1 to s2
    -- but problem is to find the minimum-> why to delete those who are already common in them, so first we will  find the 'longest common subsequence = k' from both the string and then our answer will be-> deleting all uncommon from s1(n-k) + insert all uncommon of s2(m-k)
*/

#include<bits/stdc++.h>
using namespace std;  

// tabulation method to find LCS
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) 
    {
        for (int ind2 = 1; ind2 <= m; ind2++) 
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // first find the longest common subsequence
    int k = lcs(word1, word2);

    return (n-k)+(m-k);
}


int main()
{
    string word1 = "sea";
    string word2 = "eat";

    cout << minDistance(word1, word2) << endl;

    return 0;
}


