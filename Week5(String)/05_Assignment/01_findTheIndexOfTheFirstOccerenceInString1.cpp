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
Approach:- exact same apprach than previous
    -- little bit difference in code

Time Complexity:- O((n-m+1)*m) = O(nm)
*/


#include<iostream>
#include<string>
using namespace std;

int strStr(string hayStack, string needle)
{
    int n = hayStack.length();
    int m = needle.length();

    if(m==0) return -1;

    // outer loop for main string
    for(int i=0 ; i<=(n-m) ; i++)
    {
        // inner loop for matching string
        for(int j=0 ; j<m ; j++)
        {
            if(needle[j] != hayStack[i+j]) break;
            if(j==m-1) return i;
        }
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