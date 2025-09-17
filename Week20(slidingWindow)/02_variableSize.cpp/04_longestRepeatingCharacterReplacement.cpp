/* 424

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.
*/

/*
Approach:- sliding window
    -- taking the maxfre value at each step and checking if the current window size - maxfre > k: such that we can get the different character count in the current window and if it is greater then k then we have to shrink the window from startW
*/

#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int n = s.size();

    int startW=0;
    int endW=0;

    int maxCount=0; // to store the maximum frequency of a single character in current window
    unordered_map<char,int> mp;

    int length=0;

    while(endW<n)
    {
        char ch = s[endW];
        mp[ch]++;
        maxCount = max(maxCount, mp[ch]);

        // current window size is endW-startW+1
        // we can have at most k changes so if current window size - maxCount > k then we have to shrink the window from startW
        if((endW-startW+1)-maxCount > k)
        {
            // shrink the window
            mp[s[startW]]--;
            startW++;
        }

        length = max(length, (endW-startW+1));

        endW++;
    }

    return length;
}

int main()
{
    string s = "AABABBA";
    int k=1;
    cout << characterReplacement(s, k) << endl;
    return 0;
}