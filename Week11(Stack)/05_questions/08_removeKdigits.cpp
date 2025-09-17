/* -> 402

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:
    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
Approach-
    -- if an element is greater than top of the stack then exclude that element
    -- if an element is smaller than top of the stack then exclude the top of stack
*/

#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();

    stack<int> st;

    for(int i=0 ; i<n ; i++)
    {
        while (!st.empty() && st.top()>num[i] && k)
        {
            st.pop();
            k--;
        }
        
        if(st.empty() && num[i]=='0')
            continue;

        st.push(num[i]);
    }


    // k bach gya
    while(k>0 && !st.empty())
    {
        st.pop();
        k--;
    }

    if(!st.empty())
    {
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    return "0";
}

int main()
{
    string num = "14";
    int k = 1;

    cout << removeKdigits(num, k) << endl;

    return 0;
}

