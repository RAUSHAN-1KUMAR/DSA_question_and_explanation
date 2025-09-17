/* -> 5

Given a string s, return the longest 
palindromic substring in s.


Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/

/*
Approach:-
 1.brute force
    -- two nested for loop
    -- for every character starting form i=0 to s.size() of string s, i am taking a j from j=i to s.size(), and checking (i,j) is palindrome, if yes then store it in ans only if its length is greater than ans_length.

    Time Complexity:- O(n^2*ispalindrome) = O(n^3)

 2.better approach
    -- same as we did in previous question, i.e., odd and even approach

    Time complexity:- O(n^2)

 3.Last better approach is using DP(dynamic programming memoization)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxlen = 1;
int start=0;

void helper(string &s, int i, int j)
{
    int n=s.size();

    int count=0;
    while (i>=0 && j<n && s[i]==s[j])
    {
        count=j-i+1;

        i--;
        j++;
    }

    if(count>maxlen)
    {
        maxlen=count;
        start=i+1;
    }
}

string longestPalindrome(string s)
{
    int n=s.size();

    for(int i=0 ; i<n ; i++)
    {
        // odd
        helper(s, i, i);

        // even
        helper(s, i, i+1);
    }

    return s.substr(start, maxlen);
}


int main()
{
    string s = "cbbd";

    cout << longestPalindrome(s) << endl;

    return 0;
}