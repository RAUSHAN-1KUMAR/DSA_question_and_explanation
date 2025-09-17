
/*
1. infix to postfix:
    Input: s = "a+b*(c^d-e)^(f+g*h)-i"
    Output: abcd^e-fgh*+^*+i-

    Steps:-
    1. if char is (a, A, or digits) push it into answer

    2. if char is '(' or stack is empty: push char into stack

    3. if char is ')': Pop from the stack and append to the answer until a left parenthesis '(' is encountered.

    4. if char is (+, -, *, /, ^):-
        i) if char have greater precedence than top of stack, then push it
        ii) if char have smaller or equal precedence than top of stack, pop the stack untill point i) reaches

    5. After scanning the infix expressiong, pop all operators remaining in the stack and append it to the answer.


2. infix to prefix
    Input: (A–B/C)*(A/K-L)
    Output: *-A/BC-/AKL

    Steps:-
    1. reverse the infix, Note while reversing: (A+B) will become )B+A( so we have to convert the bracket in proper direction

    2. convert the brackets: ')' -> '(' 
                             '(' -> ')'

    3. Convert the reversed infix expression to “nearly” postfix expression.
        i) if char have greater or equal precedence than top of stack, then push it
        ii) if char have smaller precedence than top of stack, pop the stack untill point i) reaches

    4. Reverse the postfix expression.


3. postfix to infix
    Input  : ab*c+
    Output : ((a*b)+c)

    Steps:- while reading the input infix
    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator(ch) between second top and first top, and form a string => second+ch+first
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.


4. prefix to infix
    Input : *-A/BC-/AKL
    Output : ((A-(B/C))*((A/K)-L))

    Steps:-
    - Steps are mostly same as postfixToInfix, the only change is we scan our infix from last and put the operator between first and second top.

    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator(ch) between second top and first top, and form a string => first+ch+second
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.


5. postfix to prefix 
    Input : ABC/-AK/L-*
    Output : *-A/BC-/AKL

    Steps:- while reading the input infix
    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator(ch) before second top and first top, and form a string => ch+second+first
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.


6. prefix to postfix
    Input : *-A/BC-/AKL
    Output : ABC/-AK/L-*

    Steps:-  
    - Steps are mostly same as postfixToPrefix, the only change is we scan our prefix from last and put the operator at last first and second top.

    1. if char is (a, A, or digits) push it into answer stack

    2. OtherWise, if symbol is an operator
        i) Pop the top 2 values from the stack. 
        ii) Put the operator at last first top and second top, and form a string -> first_top second_top operator
        iii) Push the resulted string back to stack.

    3. if there is only one value in the stack -> That value in the stack is the desired infix string.
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> pmap = {
    {'^', 6},
    {'/', 5},
    {'*', 5},
    {'-', 4},
    {'+', 4},
    {'(', 3}};
    
    
// infix to postfix
void helper(string &ans, stack<char> &st, char &newch)
{
    if (st.empty() || newch == '(')
    {
        st.push(newch);
        return;
    }

    if (newch == ')')
    {
        while (st.top() != '(')
        {
            ans.push_back(st.top());
            st.pop();
        }
        st.pop();

        return;
    }

    while (!st.empty() && pmap[newch] <= pmap[st.top()])
    {
        ans.push_back(st.top());
        st.pop();
    }

    st.push(newch);
}

string infixToPostfix(string &s)
{
    string ans = "";
    int n=s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            ans.push_back(ch);
        }
        else{
            helper(ans, st, ch);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


// postfix to infix
string postFixToInfix(string& s)
{
    stack<string> ansSt;

    for(auto &ch:s)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ansSt.push(string(1, ch));
        }
        else
        {
            string first = ansSt.top(); ansSt.pop();
            string second = ansSt.top(); ansSt.pop();

            string result = "("+second+ch+first+")"; //-> O(n1 + n2) addition take time

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


// postfix to prefix
string postFixToPrefix(string& s)
{
    stack<string> ansSt;

    for(auto &ch:s)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            ansSt.push(string(1, ch));
        }
        else
        {
            string first = ansSt.top(); ansSt.pop();
            string second = ansSt.top(); ansSt.pop();

            string result = ch+second+first; // operator second_top first_top

            ansSt.push(result);
        }
    }

    return ansSt.top();
}


int main()
{
    string s ="a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(s) << endl;
    return 0;
}