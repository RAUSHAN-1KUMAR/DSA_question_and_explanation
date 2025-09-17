/* -> 44

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    - '?' Matches any single character.
    - '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).


Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
*/

#include<iostream>
#include<vector>
using namespace std;


// recursive approach
bool isMatchHelper(string &s, int si, string &p, int pi)
{
    //base case
    if(si==s.size() && pi==p.size()){
        return true;
    }

    if(si==s.size() && pi < p.size())// this case, to handle if at end pi = *** then return true or if pi=*fdse then return false
    {
        while (pi < p.size())
        {
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }
    if(pi==p.size() && si<s.size()) return false;

  
    // single char matching
    if(s[si]==p[pi] || p[pi]=='?'){
        return isMatchHelper(s,si+1,p,pi+1);
    }

    if(p[pi]=='*'){
        // treat '*' as null/empty
        bool caseA = isMatchHelper(s,si,p,pi+1);

        // let '*' consume one char
        bool caseB = isMatchHelper(s,si+1,p,pi);

        return caseA || caseB;
    }

    return false;//-> character doesn't match;
}

bool isMatch(string s, string p)  
{
    int si = 0;//pointer index for s string
    int pi = 0;//pointer index for p string

    return isMatchHelper(s,si,p,pi);
}


// memoization
bool isMatchHelper1(string &s, int si, string &p, int pi, vector<vector<int>> &dp)
{
    if(si==s.size() && pi==p.size()){
        return true;
    }

    if(si==s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }
    if(pi==p.size() && si<s.size()) return false;

    if(dp[si][pi]!=-1) 
        return dp[si][pi];

    int ans=false;
    if(s[si]==p[pi] || p[pi]=='?'){
        ans = isMatchHelper1(s,si+1,p,pi+1, dp);
    }

    if(p[pi]=='*'){
        bool caseA = isMatchHelper1(s,si,p,pi+1, dp);
        bool caseB = isMatchHelper1(s,si+1,p,pi, dp);

        ans = caseA || caseB;
    }

    dp[si][pi] = ans;

    return dp[si][pi];
}

bool isMatch1(string s, string p)  
{
    int n=s.size();
    int m=p.size();
    int si = 0;
    int pi = 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return isMatchHelper1(s,si,p,pi, dp);
}


//tabulation method
bool isMatch2(string s, string p)  
{
    int n=s.size();
    int m=p.size();

    // Step1:
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // Step2: initialization using base case
    // 1. if(si==s.size() && pi==p.size()){return true;}
    dp[n][m] = true;

    // 2. if(si==s.size() && pi < p.size())
    for(int i=m-1 ; i>=0 ; i--){
        if(p[i]=='*' && dp[n][i+1]){
            dp[n][i] = true;
        }
        else{
            dp[n][i] = false;
        }
    }

    // 3. if(pi==p.size() && si<s.size()) return false;
    for(int i=0 ; i<n ; i++){
        dp[i][m] = false;
    }


    //Step3:
    for(int si=n-1 ; si>=0 ; si--)
    {
        for(int pi=m-1 ; pi>=0 ; pi--)
        {

            int ans=false;

            if(s[si]==p[pi] || p[pi]=='?'){
                ans = dp[si+1][pi+1];
            }

            if(p[pi]=='*'){
                bool caseA = dp[si][pi+1];
                bool caseB = dp[si+1][pi];

                ans = caseA || caseB;
            }

            dp[si][pi] = ans;
        }
    }

    return dp[0][0];
}


int main()
{
    string s = "aaaa";
    string p = "*aa";

    if(isMatch2(s,p)) cout << "True";
    else cout << "False";

    return 0;
}

