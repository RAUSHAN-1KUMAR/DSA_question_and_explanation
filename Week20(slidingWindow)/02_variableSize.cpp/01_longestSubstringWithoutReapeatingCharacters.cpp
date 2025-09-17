/* -> 3

Given a string s, find the length of the longest  substring without repeating characters.

Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
Approach:- two pointer + hashing
    -- if we found the character is already there in map then move the start pointer untill we remove it

We can optimize the erase operation, i.e., instead of moving startW one by one we can directly move it, if we store the pair of char and its index in map: length will be l-r+1 not mp.size()
*/

#include<bits/stdc++.h>
using namespace std;

// normal approach
int lengthOfLongestSubstring(string s)
{
    int n = s.size();

    int length=0;
    int startW=0;
    int endW=0;
    unordered_map<char,int> mp;

    while(endW<n)
    {
        char ch = s[endW];
        
        if(mp.count(ch)==0){
            mp[ch]++;
        }
        else{
            int size = mp.size();
            length = max(length, size);

            // now remove the startW untill we have unique characters in map
            while(mp.count(ch)){
                mp.erase(s[startW]);
                startW++;
            }

            // don't forget this
            mp[ch]++;
        }

        endW++;
    }

    // don't forget this also
    int size=mp.size();
    length = max(length, size);

    return length;
}

// optimized approach
int lengthofLongestSubstring(string s) 
{
    vector <int> mpp(256, -1);
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;

    while (right < n) 
    {
        if(mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);

        right++;
    }

    return len;
}


int main()
{
    string s = "abcbads";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}