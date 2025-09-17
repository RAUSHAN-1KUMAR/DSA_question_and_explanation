
/* 17

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> mp = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};

void helper(string &digits, vector<string> &ans, string &child, int i, int &n)
{
    if (i >= n)
    {
        ans.push_back(child);
        return;
    }

    int digit = digits[i] - '0';
    for (auto &ch : mp[digit])
    {
        child.push_back(ch);
        helper(digits, ans, child, i + 1, n);
        child.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits)
{
    int i = 0;
    int n = digits.size();
    vector<string> ans;
    string child;

    if (n == 0)
        return ans;

    helper(digits, ans, child, i, n);

    return ans;
}

int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (const string &s : ans)
    {
        cout << s << " ";
    }
    return 0;
}
