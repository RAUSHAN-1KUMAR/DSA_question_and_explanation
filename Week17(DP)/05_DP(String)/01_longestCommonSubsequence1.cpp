/* -> 1143

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.


Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/


/*
Appraoch:- recursion
    1. we just have to match the string text2 in text1. So,
        Ex:- string s1 = abc, string s2 = xyz

        i) if s1[0]==s2[0] then 1+recursive_call
        ii) if s1[0]!=s2[0] then 0+recursive_call

        return max of i) and ii)

TC:- O(2^(n+m))

Next Solution-> using DP
*/

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(string a, string b, int i, int j)
{
    // base case
    if(i>=a.length()) return 0;
    if(j>=b.length()) return 0;

    int ans=0;
    if(a[i]==b[j])// ager character match ho gya
    {
        // dono string m aage badho
        ans = 1+solveUsingRecursion(a, b, i+1, j+1);
    }
    else // ager character match nhi hua to still we have two more condition
    { 
        // 1. sirf string b m aage badho
        int caseOne = 0 + solveUsingRecursion(a, b, i, j+1);

        // 2. sirf string a m aage badho
        int caseTwo = 0 + solveUsingRecursion(a, b, i+1, j);

        ans = max(caseOne, caseTwo);
    }

    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int i=0;
    int j=i;
    int ans = solveUsingRecursion(text1, text2, i, j);

    return ans;
}


int main()
{
    string text1 = "aabc";
    string text2 = "abc";

    int ans = longestCommonSubsequence(text1, text2);

    cout << ans << endl;

    return 0;
}