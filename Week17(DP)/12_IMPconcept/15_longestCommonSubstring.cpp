/* GFG
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:
    Input: s1 = "ABCDGH", s2 = "ACDGHR"
    Output: 4
    Explanation: The longest common substrings is "CDGH" with a length of 4.

    Input: s1 = "abc", s2 = "acb"
    Output: 1
    Explanation: The longest common substrings are "a", "b", "c" all having length 1.

    Input: s1 = "YZ", s2 = "yz"
    Output: 0
*/

/*
Approach:- Lets break down the problem scenario between longest commmon subsequences and longest common substrings
    -- substrings means contiguous so it means we have to look for the continuity of equal characters, means we have to count for contiguous equal characters.
    -- the logic is to break the count whenever characters are not equal. how can we break the count recursively -> i don't know how that's why i used another variable count to increment whenever characters are equal and when its not equal, hit it zero -> but this will be a three state = 3D DP

BUT better approach is to use the tabulation technique -> given down
*/

#include <bits/stdc++.h>
using namespace std;
void printDpArray(vector<vector<int>> &dp);

// 3D DP
int helper(string &s1, string &s2, int i, int j, int count)
{
    if (i == s1.size() || j == s2.size())
    {
        return count;
    }

    int currentCount = count;
    if (s1[i] == s2[j])
    {
        currentCount = helper(s1, s2, i + 1, j + 1, count + 1);
    }

    int option1 = helper(s1, s2, i + 1, j, 0); // break the count

    int option2 = helper(s1, s2, i, j + 1, 0); // break the count

    return max({currentCount, option1, option2});
}

int longestCommonSubstr(string &s1, string &s2)
{
    int i = 0;
    int j = 0;
    int n = s1.size();
    int m = s2.size();
    int count = 0;

    int ans = helper(s1, s2, i, j, count);

    return ans;
}


// 2D DP: lets think of a different solution where count variable just vary between 0 and 1
int helper1(string &s, string &p, int i, int j, int count)
{
    if (i >= s.size() || j >= p.size())
        return 0;

    // additional case
    if (s[i] != p[j] && count == 1)
        return 0;
    if (s[i] == p[j] && count == 1)
        return 1 + helper1(s, p, i + 1, j + 1, count);

    int newSame = 0;
    if (s[i] == p[j])
    {
        newSame = 1 + helper1(s, p, i + 1, j + 1, 1);
    }

    int case1 = helper1(s, p, i + 1, j, 0);
    int case2 = helper1(s, p, i, j + 1, 0);

    return max({newSame, case1, case2});
}

int longestCommonSubstr1(string &s, string &p)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int ans = helper1(s, p, i, j, count);

    return ans;
}


// memoization of 2D approach
int helper2(string &s, string &p, int i, int j, int count, vector<vector<vector<int>>> &dp)
{
    if (i >= s.size() || j >= p.size())
        return 0;

    if (dp[i][j][count] != -1)
        return dp[i][j][count];

    // additional case
    if (s[i] != p[j] && count == 1)
        return dp[i][j][count] = 0;
    if (s[i] == p[j] && count == 1)
        return dp[i][j][count] = 1 + helper2(s, p, i + 1, j + 1, count, dp);

    int newSame = 0;
    if (s[i] == p[j])
    {
        newSame = 1 + helper2(s, p, i + 1, j + 1, 1, dp);
    }

    int case1 = helper2(s, p, i + 1, j, 0, dp);
    int case2 = helper2(s, p, i, j + 1, 0, dp);

    dp[i][j][count] = max({newSame, case1, case2});

    return dp[i][j][count];
}

int longestCommonSubstr2(string &s, string &p)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int n = s.size();
    int m = p.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));

    int ans = helper2(s, p, i, j, count, dp);

    return ans;
}


//Another approach: lets use the tabulation 2D array 
int longestCommonSubstr3(string& s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    string a=s1;
    string b=s2;

    vector<vector<int>> dp(n+1 , vector<int> (m+1,-1));

    for(int col=0 ; col<=m ; col++)
        dp[n][col]=0;

    for(int row=0 ; row<=n ; row++)
        dp[row][m]=0;

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=m-1 ; j>=0 ; j--)
        {
            int ans=0;
            if(a[i]==b[j]) 
            {
                ans = 1+dp[i+1][j+1];
                
                dp[i][j]=ans;//change1
            }
            else
            { 
                dp[i][j]=0;//change2
            }

            // change3
            // dp[i][j] = ans;
        }
    }

    printDpArray(dp);

    // lets find the maxCount
    int maxVal = INT_MIN;
    for(auto &vec:dp)
        for(int &num:vec)
            if(num>=maxVal) maxVal = num;

    return maxVal;
}


int main()
{
    string s1 = "abcde";
    string s2 = "cdefg";

    cout << longestCommonSubstr2(s1, s2) << endl;

    return 0;
}



void printDpArray(vector<vector<int>> &dp)
{
    for(auto vec:dp){
        for(auto num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
