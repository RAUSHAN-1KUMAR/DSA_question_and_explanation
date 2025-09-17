/* GFG

Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

    - Infix expression: The expression of the form an op b. When an operator is in between every pair of operands.

    - Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.


Examples :
    Input: s = "a+b*(c^d-e)^(f+g*h)-i"
    Output: abcd^e-fgh*+^*+i-
    Explanation: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-

    Input: s = "A*(B+C)/D"
    Output: ABC+*D/
    Explanation: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/

    Input: s = "(a+b)*(c+d)"
    Output: ab+cd+*
*/

/*
Approach:- just coaded the algrithm for infix to postFix

Steps:-
    1. if char is (a, A, or digits) push it into answer

    2. if char is '(' or stack is empty: push char into stack

    3. if char is ')': Pop from the stack and append to the answer until a left parenthesis '(' is encountered.

    4. if char is (+, -, *, /, ^):-
        i) if new char have greater precedence than top of stack, then push it
        ii) if new char have smaller or equal precedence than top of stack, pop the stack untill point i) reaches

    5. After scanning the infix expressiong, pop all operators remaining in the stack and append it to the answer.

TC:- O(n)
SC:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void postFixHelper(string &ans, stack<char> &st, unordered_map<char,int> &preMap, char &ch)
{
    if(st.empty() || ch=='(')
    {
        st.push(ch);
        
        return;
    }

    if(ch==')')
    {
        while(!st.empty() && st.top()!='(')
        {
            ans.push_back(st.top());
            st.pop();
        }
        st.pop();// to pop last left '('

        return;
    }

    // Now preference ka khel
    char newCh = ch;
    // greater than or equal precedence wale ko pop kerna h
    while (!st.empty() && preMap[newCh]<=preMap[st.top()])
    {
        ans.push_back(st.top());
        st.pop();
    }

    st.push(ch);
}

string infixToPostfix(string& s)
{
    string ans = "";

    // preference map
    unordered_map<char,int> preMap;
    preMap['^'] = 6;
    preMap['*'] = 5;
    preMap['/'] = 5;
    preMap['+'] = 4;
    preMap['-'] = 4;
    preMap['('] = -1;


    // stack for preference
    stack<char> st;

    for(char ch:s)
    {
        // aager ch alphabets ya digits h
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ans.push_back(ch);
        }
        else
        {
            postFixHelper(ans, st, preMap, ch);
        }
    }

    // if stack is not empty, means some of the operators missed
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    

    return ans;
}


int main()
{
    string s = "a+b-c*d/n+m";

    cout << infixToPostfix(s) << endl;

    return 0;
}