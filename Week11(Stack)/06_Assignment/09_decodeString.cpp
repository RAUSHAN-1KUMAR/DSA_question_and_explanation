/* -> 394

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/

/*
Appraoch:- steps are mentioned within the code
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    string ans = "";

    for(char ch:s)
    {
        if(ch==']')
        {
            string addS="";
            while (st.top()!="[")// making string
            {
                addS += st.top();
                st.pop();
            }
            st.pop();//-> removing opening bracket


            // Now forming digit to repeat the string addS
            string digit ="";
            while(!st.empty() && isdigit(st.top()[0]))
            {
                digit += st.top();
                st.pop();
            }
            reverse(digit.begin(), digit.end());
            int n = stoi(digit);
            

            // forming the repeated string
            string repeatedAddS = "";
            for(int i=0 ; i<n ; i++)
            {
                repeatedAddS += addS;
            }
            st.push(repeatedAddS);// aur stack ke uper phir push ker diye, for nested bracket
            
        }
        else{
            st.push(string(1,ch));
        }
    }

    // forming final answer
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
    
}


int main()
{
    string s = "2[abc]3[cd]ef";

    string ans = decodeString(s);
    
    cout << ans << endl;

    return 0;
}