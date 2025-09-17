/* -> 32

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
*/

/*
Approach:- question is good, sahi se observation ki zarurat ki kaise lengthh nikale.
    -- stack m index push krengen
    -- intially stack m -1 h taki invalid parenthesis ko handle ker sake
    
    Logic:
        - ager ek opening h to uska closing hona chahiye valid ke liye:
        - jab opening aya to push kerdo index;
        - jab closing aya to pop kerdo and length find kro i-st.top(), pehle pop kiye taki length usse pehle wake index se nikal sake

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);

    int maxLen = 0;

    for(int i=0 ; i<s.size() ; i++)
    {
        char ch = s[i];

        if(ch=='('){
            st.push(i);
        }
        else{
            st.pop();

            // stack empty ho gya matlab invalid bracket tha
            if(st.empty())
            {
                st.push(i);// push ker rhe taki stack empty na rhe aur baad m iska use ker rhe length ko nikalne m
            }
            else{// ager stack empty nhi h matlab ')' kisi opening ko cancel kiya h
                int len = i-st.top();
                maxLen = max(len, maxLen);
            }
        }
    }

    return maxLen;
}

int main()
{
    string s = "))(()()(()))(())))";

    cout << longestValidParentheses(s) << endl;

    return 0;
}