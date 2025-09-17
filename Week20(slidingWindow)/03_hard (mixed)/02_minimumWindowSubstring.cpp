/* 76

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 
Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

Example 3:
    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
*/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) 
{
    unordered_map<char,int>mp;
    for(auto ch:t)
    {
        mp[ch]++;
    }

    int i=0;
    int j=0;
    int n=s.size();
    int count=mp.size();

    int minLen=INT_MAX;
    int startIndex=-1;

    while(j<n)
    {
        //expansion
        if(mp.find(s[j])!=mp.end())
        {
            mp[s[j]]--;

            if(mp[s[j]]==0)
            {
                count--;
            }
        }

        //shrinking
        while(count==0 && i<=j)
        {
            //ans update
            int len = j-i+1;

            if(len < minLen)
            {
                minLen=len;
                startIndex=i;
            }

            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]++;

                if(mp[s[i]]==1)
                {
                    count++;
                }
            }

            i++;
        }

        j++;
    }

    if(startIndex==-1)
    {
        return "";
    }
    return s.substr(startIndex,minLen);
}


int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = minWindow(s,t);
    cout << ans << endl;
    return 0;
}

