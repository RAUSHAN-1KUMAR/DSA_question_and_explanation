/* -> 301

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:
    Input: s = "()())()"
    Output: ["(())()","()()()"]

Example 2:
    Input: s = "(a)())()"
    Output: ["(a())()","(a)()()"]

Example 3:
    Input: s = ")("
    Output: [""]
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> removeInvalidParentheses(string s) 
{
        
}

int main()
{
    string s = "(a)())()";
    vector<string> ans = removeInvalidParentheses(s);
    for(auto &s:ans){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}