/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 
Example 1:
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/

/*
Approach:- two pointer + recursion
    -- taking two pointer at start and end, and then
        i) if both character are same then move both pointer inward
        ii) if character are not same then we have to options -> either we insert the corresponding same character of end at start(end-1) or we insert the corresponding same character of start at end(start+1)

    1. resursive 
    2. memoization
    3. tabulation

Easy approach -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);

// recursive
int helper(string &s, int start, int end)
{
    if(start>=end) return 0;

     
    int ans=0;
    if(s[start]==s[end])// if same then move inward
        ans = helper(s, start+1, end-1);
    else 
    { 
        // if not same then either insert at start or at end
        ans = 1 + min(helper(s, start+1, end), helper(s, start, end-1));
    }
    
    return ans;
}

int minInsertions(string s)
{
    int start=0;
    int end=s.size()-1;

    return helper(s, start, end);
}


// memoization
int helper1(string &s, int start, int end, vector<vector<int>> &dp)
{
    if(start>=end) return 0;

    if(dp[start][end]!=-1)
        return dp[start][end];
     
    int ans=0;
    if(s[start]==s[end])
        ans = helper1(s, start+1, end-1, dp);
    else 
    { 
        ans = 1 + min(helper1(s, start+1, end, dp), helper1(s, start, end-1, dp));
    }

    dp[start][end]=ans;
    
    return ans;
}

int minInsertions1(string s)
{
    int n=s.size();
    int start=0;
    int end=s.size()-1;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper1(s, start, end, dp);
}

// tabulation
int minInsertions2(string s)
{
    int n=s.size();
    int low=0;
    int high=s.size()-1;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    // initialization
    for(int i=0; i<n; i++)
        for(int j=0 ; j<n; j++)
            if(i>=j)
                dp[i][j]=0;

    // last step: using the memoization code and also handle the variable states carefully
    for(int start=n-1 ; start>=0 ; start--)
    {
        for(int end=start+1 ; end<n ; end++)
        {
            int ans=0;
            if(s[start]==s[end])
                ans = dp[start+1][end-1];
            else 
            { 
                ans = 1 + min(dp[start+1][end], dp[start][end-1]);
            }

            dp[start][end]=ans;
        }
    }

    printDpArray(dp);

    return dp[0][n-1];
}


int main()
{
    string s = "leetcode";
    cout << minInsertions2(s) << endl;
    return 0;
}

void printDpArray(vector<vector<int>> &dp)
{
    for(auto vec:dp)
    {
        for(int num:vec)
            cout << num << " ";

        cout << endl;
    }
}

