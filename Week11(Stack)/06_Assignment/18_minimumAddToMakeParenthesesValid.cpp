/* 921

A parentheses string is valid if and only if:
    - It is the empty string,
    - It can be written as AB (A concatenated with B), where A and B are valid strings, or
    - It can be written as (A), where A is a valid string.
    - You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 
Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3
*/

/*
Appraoch:- 
    - ager aane wala bracket opening('(') h to push kerdo, aur ager closing(')') h to check kro ki kya top p opening h:- 
        (i) ager ha to pop kerdo
        (ii) ager nhi to push kerdo
    - last m jitna stack ka size h wahi answer h
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int minAddToMakeValid(string s)
{
    stack<char> st;

    int ans=0;

    for(auto ch:s)
    {
        if(ch=='('){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    return st.size();
}


int main()
{
    string s = ")))((())()))";

    cout << minAddToMakeValid(s) << endl;

    return 0;
}