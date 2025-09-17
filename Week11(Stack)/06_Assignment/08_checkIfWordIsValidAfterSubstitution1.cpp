/* -> 1003

Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
    - Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.

Return true if s is a valid string, otherwise, return false.

 

Example 1:
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.

Example 2:
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.

Example 3:
Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.

*/

/*
Appraoch:- using stack
 - Logic:
    stack m push ke rhe a -> b -> c ...
        1. to push kerte waqt ager c milta h, to ham stack m top two element nikal ke check kerengen ki kya wo a->b h, ager ha top pop both

        2. valid push bhi check ker sakte h
            (i) ager start hi a se nhi ho rha matlab, invalid
            (ii) b tabhi push hoga jab top of stack a ho nhi to return false
            (iii) c ko push nhi ker rhe, c milte ke top m ager b h to pop, phir a to again pop, nhi to return false
        
        Note:- her pop() operation m check ker lengen ki kya stack empty to nhi.

        2. end m stack empty h matlab valid

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool isValid(string s)
{
    // base condition
    if(s[0] != 'a') return false;

    stack<char> st;
    for(char ch:s)
    {
        if(ch=='a') st.push(ch);//-> ager a aaya
        else if(ch=='b')//-> ager b aaya
        {
            if(!st.empty() && st.top()=='a'){
                st.push(ch);
            }
            else{
                return false;
            }
        }
        else//-> ager c aaya
        {
            if(!st.empty() &&  st.top()=='b')
            {
                st.pop();
                if(!st.empty() && st.top()=='a'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    return st.empty() ? true : false;
}

int main()
{
    string s = "abcabcababcc";

    if(isValid(s)) cout << "valid";
    else cout << "Invalid";

    return 0;
} 