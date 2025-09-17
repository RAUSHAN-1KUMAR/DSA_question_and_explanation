/* Q.no: -> 647

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.


Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

/*
Approach:- two pointer
    -- previous we were checking plaindrome from i=0 to j=n-1, now we will check form given position to outward.
    -- but we will check for two case 
        1. for odd(i==j)
        2. for even(i,j=i+1)

        both the above two approach will be applied for each element of string

*/

#include<iostream>
using namespace  std;

int expand(string s, int i, int j)
{
    int count=0;
    while (i>=0 && j<s.length() && s[i]==s[j])
    {
        count++;
        i--;
        j++;
    }
    
    return count;
}

int countSubstings(string s)
{
    int totalCount = 0;

    for(int center=0 ; center<s.length() ; center++)
    {
        // ODD
        int oddkaAns = expand(s,center,center);

        //EVEN
        int evenKaAns = expand(s,center,center+1);

        totalCount += oddkaAns+evenKaAns;
    }

    return totalCount;
}


int main()
{
    string str = "aaa";

    cout << countSubstings(str) << endl;

    return 0;
}