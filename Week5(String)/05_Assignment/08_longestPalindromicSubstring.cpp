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
Approach:- brute force
    -- two nested for loop
    -- for every character starting form i=0 to s.size() of string s, i am taking a j from j=i to s.size(), and checking (i,j) is palindrome, if yes then store it in ans only if its length is greater than ans_length.

time complexity:- O(n^2*ispalindrome) = O(n^3)
    -- so second better approach is DP i.e., dynamic programming
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    while(i<j){
        if(s[i] != s[j]) return false;

        i++;
        j--;
    }

    return true;
}

string longestPalindrome(string s)
{
    string ans = "";

    for(int i=0 ; i<(s.size()) ; i++)
    {
        for(int j=i ; j<s.size() ; j++)
        {
            if(isPalindrome(s,i,j)){
                string t = s.substr(i,j-i+1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }

    return ans;
}

int main()
{
    string s = "cbbd";

    cout << longestPalindrome(s) << endl;

    return 0;
}