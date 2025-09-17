/* -> 5

Given a string s, return the longest 
palindromic substring in s.


Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

Example 2:
    Input: s = "cbbd"
    Output: "bb"
*/


/*
Approach:- solved in Week String(question)
    -- In this we can use the same code, but the solve function should be a recursive function for the memoization technique.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxlen = 1;
int start=0;


bool solve(string &s, int i, int j, vector<vector<int>> &dp)
{
    if(i>=j) true;

    //Step3:
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    bool flag=false;

    if(s[i]==s[j]){
        flag=solve(s,i+1, j-1, dp);
    }

    if(flag){
        int currlen = j-i+1;
        if(currlen>maxlen){
            maxlen=currlen;
            start=i;
        }
    }

    //Step2:
    dp[i][j]=flag;

    return dp[i][j];
}


string longestPalindrome(string s)
{
    int n=s.size();

    //Step1:
    vector<vector<int>> dp(n, vector<int> (n,-1));

    for(int i=0 ; i<n ; i++)
    {
        for(int j=i ; j<n ; j++)
        {
            bool t = solve(s,i,j, dp);
        }
    }

    return s.substr(start,maxlen);
}


int main()
{
    string s = "eabcb";

    cout << longestPalindrome(s) << endl;

    return 0;
}