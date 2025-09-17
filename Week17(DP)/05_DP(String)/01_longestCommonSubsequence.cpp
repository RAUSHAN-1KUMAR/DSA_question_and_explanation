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
Appraoch:- 
    1. brute force:- we have given two strings, text1 and text2. find all the subsequences of text1 using recursion and store it, also do the same thing for text2 and then check which one is longest common subsequence

Note:- This solution will give TLE
Better Solution:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// using recursion: to store the subsequence of string text1 in map
void allSubsequences(string &s, map<string, int> &mp, int index, string &output)
{
    if(index==s.size())
    {
        mp[output]++;
        return;
    }

    //exclude
    allSubsequences(s, mp, index+1, output);

    //include
    output.push_back(s[index]);
    allSubsequences(s, mp, index+1, output);
    output.pop_back();
}

// using recursion: to check the presence of subsequence of string text2 in map of string text1
void checkingSubsequences(string &s, int &lonMatching, int matching, int index, string &output, map<string, int> &mp)
{
    // base case
    if(index == s.size())
    {
        // checking
        if(mp.find(output) != mp.end())
        {
            matching = output.size();
            lonMatching = max(lonMatching, matching);
        }
        return;
    }

    // exclude
    checkingSubsequences(s, lonMatching, matching
    , index+1, output, mp);

    // include
    output.push_back(s[index]);
    checkingSubsequences(s, lonMatching, matching, index+1, output, mp);
    output.pop_back();
}


int longestCommonSubsequence(string text1, string text2)
{
    // forming the map of all subsequences of text1 string.
    map<string, int> mp;
    string output;
    int index = 0;
    allSubsequences(text1, mp, index, output);

    // now checking for each subsequences of text2
    int lonMatching = 0;
    int matching = 0;
    index = 0;
    output = "";
    checkingSubsequences(text2, lonMatching, matching, index, output, mp);

    return lonMatching;
}


int main()
{
    string text1 = "abc";
    string text2 = "bec";

    int ans = longestCommonSubsequence(text1, text2);

    cout << ans << endl;

    return 0;
}