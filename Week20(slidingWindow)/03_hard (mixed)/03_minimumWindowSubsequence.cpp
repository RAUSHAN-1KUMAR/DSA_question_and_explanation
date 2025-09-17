/* GFG

Given two strings s1 and s2, find the smallest contiguous substring of s1 in which s2 appears as a subsequence.
    - The characters of s2 must appear in the same order within the substring, but not necessarily consecutively.

    - If multiple substrings of the same minimum length satisfy the condition, return the one that appears earliest in s1.

    - If no such substring exists, return an empty string.

    - Both s1 and s2 consist only of lowercase English letters.


Examples:
    Input: s1 = "geeksforgeeks", s2 = "eksrg"
    Output: "eksforg"
    Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is smallest and leftmost among all possible valid substrings of s1.

    Input: s1 = "abcdebdde", s2 = "bde" 
    Output: "bcde"
    Explanation: "bcde" and "bdde" are two substring of s1 where s2 occurs as subsequence but "bcde" occur first so we return that.

    Input: s1 = "ad", s2 = "b" 
    Output: ""
    Explanation: There is no substring exists.
*/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    
}

int main()
{
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << minWindow(s1,s2) << endl;
    return 0;
}