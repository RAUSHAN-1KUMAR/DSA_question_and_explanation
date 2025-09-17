/* GFG

You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:
    Input: s = "aabacbebebe", k = 3
    Output: 7
    Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

    Input: s = "aaaa", k = 2
    Output: -1
    Explanation: There's no substring with 2 distinct characters.

    Input: s = "aabaaab", k = 2
    Output: 7
    Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

*/

#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    int n = s.size();

    int startWindow=0;
    int endWindow=0;

    unordered_map<char,int> mp; // to store the frequency of characters in current window

    int maxLength=-1;

    while(endWindow<n)
    {
        char ch = s[endWindow];
        mp[ch]++;

        while(mp.size()>k) // we have more than k distinct characters in current window
        {
            // shrink the window from startWindow
            mp[s[startWindow]]--;
            if(mp[s[startWindow]]==0)
                mp.erase(s[startWindow]);

            startWindow++;
        }

        // now check if we have exactly k distinct characters in current window
        if(mp.size()==k)
        {
            maxLength = max(maxLength, endWindow-startWindow+1);
        }

        endWindow++;
    }

    return maxLength;
}

int main()
{
    string s = "aabacbebebe";
    int k=3;
    cout<<longestKSubstr(s, k)<<endl;
    return 0;
}