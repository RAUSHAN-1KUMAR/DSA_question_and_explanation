/* -> 1021

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/

/*
Appraoch:- similar to that appraoch which is done in generate parenthesis of recursion session
    -- counting the left(for opening bracket) and right(for closing braket), it the count of left and right is equal then it means we have to remove the first and last of formed string.
*/

#include<iostream>
#include<vector>
using namespace std;

string removeOuterParentheses(string s) 
{
    string ans = "";

    string formed = "";

    int leftParen = 0;
    int rightParen = 0;
    for(int i=0 ; i<s.size() ; i++)
    {

        if(s[i]=='(') leftParen++;
        else rightParen++;

        formed.push_back(s[i]);

        if(leftParen==rightParen){
            ans += formed.substr(1, formed.length()-2);
            formed = "";
        }

    }

    return ans;
}

int main()
{
    string input = "(()())(())";

    string ans = removeOuterParentheses(input);

    cout << ans << endl;
    
    return 0;
}