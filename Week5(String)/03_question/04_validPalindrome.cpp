/* Q.no: 680

Given a string s, return true if the s can be palindrome after deleting at most one character from it.


Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
*/

/*
Appraoch:- two pointer(i=0, j=n-1)
    -- if a[i]==a[j] h tab to thik h
    -- if a[i]!=a[j] to:
        1. palindrome check kro i+1 se j tak ke liye
        2. palindrome check kro i se j-1 tak ke liye
            ager kisi ek me true aya to answer true, nhi to false
*/

#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j]) return false;
        else{
            i++;
            j--;
        }
    }

    return true;
}

bool validPalindrome(string s)
{
    int i=0;
    int j=s.length()-1;

    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            // check palindrome for remaining string after removal
            bool ans1 = checkPalindrome(s, i+1, j);
            bool ans2 = checkPalindrome(s, i, j-1);

            return ans1||ans2;
        }
    }

    return true;
}

int main()
{
    string str = "abca";

    bool ans = validPalindrome(str);

    if(ans) cout << "true";
    else cout << "false";

    return 0;
}