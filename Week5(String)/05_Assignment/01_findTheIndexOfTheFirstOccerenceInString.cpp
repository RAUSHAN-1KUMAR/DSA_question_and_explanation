/* -> 28

Given two strings 'needle' and 'haystack', return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

/*
My approach:-   
    -- run a loop form 0 to strLen-subLen i.e., till mainlenght of string - length of matching string.\
    -- her ek index i ke liye ham check ker rhe h ki kya wanha se lekar matching string ke length tak wala character equal h matching string wale character se, ager ha to return that index.

Time Complexity:- O((n-m+1)*m) = O(nm)
*/


#include<iostream>
#include<string>
using namespace std;

int strStr(string hayStack, string needle)
{
    int strLen = hayStack.length();
    int subLen = needle.length();

    if(subLen==0) return -1;

    // outer loop for main string
    for(int i=0 ; i<=(strLen-subLen) ; i++)
    {
        int j=0;

        // inner loop for matching string
        while(j<subLen && hayStack[i+j]==needle[j]){
            j++;
        }

        if(j==subLen) return i;
    }

    return -1;
}


int main()
{
    string hayStack = "sadbutsad";
    string needle = "sad";

    int ans = strStr(hayStack, needle);

    cout << ans << endl;

    return 0;
}