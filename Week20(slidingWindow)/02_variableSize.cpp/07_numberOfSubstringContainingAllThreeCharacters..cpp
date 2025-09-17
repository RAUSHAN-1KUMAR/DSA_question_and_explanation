/* 1358

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 
Example 1:
    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:
    Input: s = "aaacb"
    Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

*/

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int n = s.size();

    int startWindow=0;
    int endWindow=0;

    unordered_map<char,int> mp; // to store the frequency of characters in current window

    int count=0;

    while(endWindow<n)
    {
        char ch = s[endWindow];
        mp[ch]++;

        while(mp.size()==3) // we have all three characters in current window
        {
            // all the substrings starting from startWindow to end of string will have all three characters
            count += (n-endWindow);

            // now we will shrink the window from startWindow
            mp[s[startWindow]]--;
            
            if(mp[s[startWindow]]==0)
                mp.erase(s[startWindow]);

            startWindow++;
        }

        endWindow++;
    }

    return count;
}

int main()
{
    string s = "abcabc";
    cout<<numberOfSubstrings(s)<<endl;
    return 0;
}