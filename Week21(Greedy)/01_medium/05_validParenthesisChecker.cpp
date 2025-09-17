/* 678

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
    - Any left parenthesis '(' must have a corresponding right parenthesis ')'.

    - Any right parenthesis ')' must have a corresponding left parenthesis '('.

    - Left parenthesis '(' must go before the corresponding right parenthesis ')'.

    - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true

*/

/*
Approach:-
1. DP

2. Greedy
*/

#include<bits/stdc++.h>
using namespace std;

//( recusiong: TC: O(3^n) , SC: O(n))
bool funRec(string &s, int i, int cnt)
{
    if(cnt<0) return false;
    if(i==s.size()) return cnt==0;
    
    if(s[i]=='(') return funRec(s, i+1, cnt+1);
    else if(s[i]==')') return funRec(s, i+1, cnt-1);
    else // if it is '*'
        return funRec(s, i+1, cnt+1) || funRec(s, i+1, cnt-1) || funRec(s, i+1, cnt);
}

// DP approach
// (TC: O(n^2) , SC: O(n^2))
int helper(string &s, int i, int cnt, vector<vector<int>> &dp)
{
    if(cnt<0) return false;
    if(i==s.size()) return cnt==0;

    if(dp[i][cnt]!=-1) return dp[i][cnt];

    if(s[i]=='(') return dp[i][cnt] = helper(s, i+1, cnt+1, dp);
    else if(s[i]==')') return dp[i][cnt] = helper(s, i+1, cnt-1, dp);
    else // if it is '*'
        return dp[i][cnt] = helper(s, i+1, cnt+1, dp) || helper(s, i+1, cnt-1, dp) || helper(s, i+1, cnt, dp);
}

bool funDP(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1)); // n+1 because cnt can go from 0 to n
    return helper(s, 0, 0, dp);
}   


// Greedy approach (range based logic)
bool checkValidString(string s) 
{
    int min=0, max=0;

    for(char &ch:s)
    {
        if(ch=='(')
        {
            min = min+1;
            max = max+1;
        }
        else if(ch==')')
        {
            min = min-1;
            max = max-1;
        }
        else
        {
            min = min-1;
            max = max+1;
        }

        if(min<0) min=0; // if min<0, then we can consider '*' as '(' to balance the extra ')'
        if(max<0) return false; // if max<0, then we have extra ')' which cannot be balanced
    }

    return min==0;
}


int main()
{
    string s = "(*))";
    cout << (checkValidString(s) ? "true" : "false") << endl;
    return 0;
}

