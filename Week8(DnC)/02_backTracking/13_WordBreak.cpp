/* 139

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:
    Input: s = "leetcode", wordDict = ["leet","code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
    Input: s = "applepenapple", wordDict = ["apple","pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    Note that you are allowed to reuse a dictionary word.

Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: false
*/

/*
Approach:
    -- first use hash map to mark the presence of each wordDict
    -- then apply adjacent two pointer approach, to find the substring in map

TLE -> can be reduced by DP approach
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(int start, string &s, unordered_set<string> &dict)
{
    if (start >= s.length())
        return true;

    // trying all possible substrings starting from 'start' index
    for (int end = start; end <= s.size(); end++)
    {
        // current substring from start to end
        string word = s.substr(start, end - start + 1);

        // if it is present in the dictionary
        // then we can check for the next substring
        if (dict.count(word))
        {
            if (solve(end + 1, s, dict))
                return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    // storing all dict words into set to check presence of word in O(1)
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    return solve(0, s, dict);
}

int main()
{

    return 0;
}