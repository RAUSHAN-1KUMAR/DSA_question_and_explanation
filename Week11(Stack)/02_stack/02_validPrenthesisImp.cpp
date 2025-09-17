/* -> 20

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for(int i=0 ; i<s.size() ; i++)
    {
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            st.push(ch);
        }
        else
        {
            // check stack is empty or not
            if(!st.empty()){
                if(ch==')' && st.top()=='(') st.pop();
                else if(ch=='}' && st.top()=='{') st.pop();
                else if(ch==']' && st.top()=='[') st.pop();
                else return false;
            }
            else{
                return false;
            }
        }
    }

    // if stack is not empty
    if(st.size() != 0) return false;

    return true;
}

int main()
{
    string s = "(){}[()]";

    if(isValid(s)) cout << "Valid";
    else cout << "Invalid";

    return 0;
}