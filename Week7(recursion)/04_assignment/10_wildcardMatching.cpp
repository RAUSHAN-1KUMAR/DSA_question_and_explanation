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

int main()
{
    string s = "aaaa";
    string p = "*aa";

    if(isMatch(s,p)) cout << "True";
    else cout << "False";

    return 0;
}