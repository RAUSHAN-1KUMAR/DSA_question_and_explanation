/* GFG

Given an infix expression, the task is to convert it to a prefix expression.

    - Infix Expression: The expression of type a ‘operator’ b (a+b, where + is an operator) i.e., when the operator is between two operands.

    - Prefix Expression: The expression of type ‘operator’ a b (+ab where + is an operator) i.e., when the operator is placed before the operands.


Examples: 
    Input: A*B+C/D
    Output: +*AB/CD 


    Input: (A–B/C)*(A/K-L)
    Output: *-A/BC-/AKL

*/

/*
Approach:- just coaded the algrithm for infix to prefix

Steps:-
    1. reverse the infix, Note while reversing: (A+B) will become )B+A( so we have to convert the bracket in proper direction

    2. convert the brackets: ')' -> '(' 
                             '(' -> ')'

    3. Convert the reversed infix expression to “nearly” postfix expression.
        - While converting to postfix expression, instead of using pop operation to pop operators with greater than or equal precedence, here we will only pop the operators from stack that have greater precedence.

    4. Reverse the postfix expression.

TC:- O(n)
SC:- O(n)

Notice the change done to the code of infix to postfix
*/


#include<bits/stdc++.h>
using namespace std;

void prefixHelper(string &ans, stack<char> &st, unordered_map<char,int> &preMap, char &ch)
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
        st.pop();// to pop '('

        return;
    }

    char newCh = ch;
    //Change3: step3 -> only greater ko pop kerna h i.e., 
    while (!st.empty() && preMap[newCh]<preMap[st.top()])
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    st.push(ch);
}

string infixToPrefix(string& s)
{
    // Change1: step1
    reverse(s.begin(), s.end());

    //Change2; step2
    for(char &ch:s)
    {
        if(ch==')')
            ch='(';
        else if(ch=='(')
            ch=')';
    }

    string ans = "";

    unordered_map<char,int> preMap;
    preMap['('] = -1;
    preMap['^'] = 6;
    preMap['*'] = 5;
    preMap['/'] = 5;
    preMap['+'] = 4;
    preMap['-'] = 4;


    stack<char> st;

    for(char ch:s)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ans.push_back(ch);
        }
        else
        {
            prefixHelper(ans, st, preMap, ch);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    //change4: step4
    reverse(ans.begin(), ans.end());    

    return ans;
}


int main()
{
    string s = "(A+B)*C-D*F";

    cout << infixToPrefix(s) << endl;

    return 0;
}




