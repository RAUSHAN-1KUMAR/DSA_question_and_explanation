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
Approach:- Using tabulation method
    -- if character matches then it is fine go and check for dp[i+1][j+1], but
    -- if character doesn't matches then just put dp[i][j]=0, no need to go further, becuase we have to break the continuity there
    -- on computing we can use a maxCount to update it on each iteration or we can also compute at the last when our dp array will be ready.
    -- Notice the changes made

    And then we can also do "space optimization"

In tabulation method we don't need count, becuase we will already look for every possible combination of i and j
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);


int longestCommonSubstr(string& s1, string &s2)
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
    string s1 = "abcmlde";
    string s2 = "abcpocdep";
    
    cout << longestCommonSubstr(s1, s2) << endl;

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


