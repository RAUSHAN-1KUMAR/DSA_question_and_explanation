/* -> 115

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    RABB b IT -> RABBIT
    RA b BBIT -> RABBIT
    RAB b BIT -> RABBIT


Example 2:
    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    As shown below, there are 5 ways you can generate "bag" from s.
    BAbGbag -> BAG
    BAbgbaG -> BAG
    BabgbAG -> BAG
    baBgbAG -> BAG
    babgBAG -> BAG
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(string &s, string &t, int i, int j)
{
    // base case
    if(i>=s.size() && j>=t.size()) return 1;
    else if(i>=s.size()&&j<t.size()) return 0;
    else if(i<s.size()&&j>=t.size()) return 1;

    // if character matches
    int ansOne=0;
    if(s[i]==t[j])
        ansOne = helper(s, t, i+1, j+1);

    // either matches or not
    int ansTwo=helper(s, t, i+1, j); // why we have just incremented i not j, because we have to find string 't' in 's': j is for string t, i is for string s

    return ansOne+ansTwo;
}

int numDistinct(string s, string t)
{
    int i=0;
    int j=0;

    int ans = helper(s, t, i, j);

    return ans;
}


// memoization
int helper1(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(i>=s.size() && j>=t.size()) return 1;
    else if(i>=s.size()&&j<t.size()) return 0;
    else if(i<s.size()&&j>=t.size()) return 1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    // if character matches
    int ansOne=0;
    if(s[i]==t[j])
        ansOne = helper1(s, t, i+1, j+1,dp);

    // either matches or not
    int ansTwo=helper1(s, t, i+1, j,dp);

    dp[i][j] = ansOne+ansTwo;

    return dp[i][j];
}

int numDistinct1(string s, string t)
{
    int i=0;
    int j=0;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));

    int ans = helper1(s, t, i, j,dp);

    return ans;
}

int main()
{
    string s = "rabbbit";
    string t = "rabbit";

    cout << numDistinct1(s, t) << endl;

    return 0;
}