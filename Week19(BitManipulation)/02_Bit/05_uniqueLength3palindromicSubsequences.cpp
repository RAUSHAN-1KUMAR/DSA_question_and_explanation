/* -> 1930
Given a string s, return the number of 'unique' palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    * For example, "ace" is a subsequence of "abcde".
 

Example 1:
    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
    - "aba" (subsequence of "aabca")
    - "aaa" (subsequence of "aabca")
    - "aca" (subsequence of "aabca")

Example 2:
    Input: s = "adc"
    Output: 0
    Explanation: There are no palindromic subsequences of length 3 in "adc".

Example 3:
Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
*/

/*
Approach:-
    1. without bit manipulation:-
        -- answer will be, sum of total no. of unique character in between the first and last occurence of each unique character

        TC:- O(n)

    2. with bit manipulation
        -- first lets understand how can you use bit mask to find unique character in a given string -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// 1. without bit manipulation
int countPalindromicSubsequence(string s)
{
    // first collect all unique characters
    unordered_set<char> letters;
    for(char &ch:s){
        letters.insert(ch);
    }

    /*
    We can also solve it without using set, we can use two vector(first and last) to store the first and last occu of each character in a single pass
    */

    // then count all unique characters in between first and last occur of each uniq char
    int ans=0;
    for(char ch:letters){
        int i=-1;
        int j=0;
        
        // finding first and last occurence of each unique characters
        for(int k=0; k<s.size();k++){
            if(s[k]==ch){
                if(i==-1) i=k;
                j=k;
            }
        }

        // collecting uniq characters between first and last occur
        unordered_set<char> uniqChar;
        for(int c=i+1; c<j; c++){
            uniqChar.insert(s[c]);
        }

        ans += uniqChar.size();
    }

    return ans;
}



int main()
{
    string s = "aabccac";
    cout << countPalindromicSubsequence(s) << endl;
    return 0;
}