/* 131
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.


Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]

Example 2:
    Input: s = "a"
    Output: [["a"]]
*/

/*
Approach:- 
    -- start form index 0 and find substring which is palindrome, then for next recursive call, the index will start from end of the palindrome substring found.
*/

// TC-> O(2^n*n*k)

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j, int &n)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void helper(string &s, vector<vector<string>> &ans, vector<string> &child, int i, int &n)
{
    if (i >= n)
    {
        ans.push_back(child);
        return;
    }

    for (int j = i; j < n; j++)
    {
        if (isPalindrome(s, i, j, n))
        {
            string curr = s.substr(i, j - i + 1);

            child.push_back(curr);

            helper(s, ans, child, j + 1, n);

            child.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.size();
    int i = 0;
    vector<vector<string>> ans;
    vector<string> child;

    helper(s, ans, child, i, n);

    return ans;
}


int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for(auto &v:ans){
        for(string &ch:v){
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}

