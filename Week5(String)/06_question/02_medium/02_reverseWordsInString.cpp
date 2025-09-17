/* -> 151

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

/*
Approach:- two pointer
    -- input:- " the sky   is   blue";
       output:- "blue is the sky";

    Step1: removed the unwanted white spaces: "the sky is blue"
    Step2: reversing the obtained string: "eulb si yks eht"
    Step2: reverse each word one by one: "blue is sky the"
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removingUnwantedWhitespaces(string &s)
{
    int n = s.length();

    int i = -1;
    int forsingleSpace = 0;

    for (int j = 0; j < n; j++)
    {
        if (s[j] != ' ')
        {
            i++;
            s[i] = s[j];
            forsingleSpace = 1;
        }
        else
        {
            if (forsingleSpace == 1)
            {
                i++;
                s[i] = ' ';
                forsingleSpace = 0;
            }
        }
    }

    s.erase(s.begin() + i + 1, s.end());

    if (s[s.length() - 1] == ' ')
        s.pop_back();
}

string reverseWords(string s)
{
    // removing extra whitespaces
    removingUnwantedWhitespaces(s);

    // reversing the string
    reverse(s.begin(), s.end());

    // now forming the required answer
    // reversing the each word one by one
    int i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (s[j] == ' ' || j == s.length() - 1)
        {
            int k = j == s.length() - 1 ? j : j - 1;
            while (i <= k)
            {
                swap(s[i], s[k]);
                i++, k--;
            }
            i = j + 1;
        }
    }

    return s;
}

// optimal approach
string reverseWords1(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int i = 0;
    int l = 0, r = 0;
    while (i < n)
    {

        while (i < n && s[i] != ' '){
            s[r++] = s[i++];
        }

        if (l < r){
            reverse(s.begin() + l, s.begin() + r);
            s[r] = ' ';
            r++;
            l = r;
        }
        i++;
    }
    string ans = s.substr(0, r - 1);
    return ans;
}

int main()
{
    string str = "the sky is blue";

    string ans = reverseWords(str);

    cout << ans;

    return 0;
}