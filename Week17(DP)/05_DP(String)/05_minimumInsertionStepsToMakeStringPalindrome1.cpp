/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 
Example 1:
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/

/*
Approach:- This approach uses the approach of the question "longest common palindrome"
    -- lets build logic from the very begining:- one way to make the given string palindrome is to concatenate the reverse of whole string into the given string but it has said to return minimum insertion, So what we can do know
    -- think for it, the part of our given string who is already in palindrome leave it, we just have to make other part palindrome, 
    -- for that we will have to count the length of string who is not palindrome and then the insertion will be equivalent to that length. So, just find the length of longest palindrome subsequece and then subtract from the length of string(n);

    Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);

// recursive (same code of longest commmon palindrome)
int helper(string &text1, string &text2, int i, int j)
{
    if(i>=text1.size() || j>=text2.size())
        return 0;
     
    int ans=0;
    if(text1[i]==text2[j])
        ans = 1 + helper(text1, text2, i+1, j+1);
    else 
    { 
        ans = max(helper(text1, text2, i+1, j), helper(text1, text2, i, j+1));
    }
    
    return ans;
}

int minInsertions(string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    int i=0;
    int j=0;

    int ans = helper(s1, s2, i, j); // we got the longest palindrome in our string

    // now we just have to return the n-ans;
    return s.size()-ans;
}


int main()
{
    string s = "leetcode";
    cout << minInsertions(s) << endl;
    return 0;
}

void printDpArray(vector<vector<int>> &dp)
{
    for(auto vec:dp)
    {
        for(int num:vec)
            cout << num << " ";

        cout << endl;
    }
}

