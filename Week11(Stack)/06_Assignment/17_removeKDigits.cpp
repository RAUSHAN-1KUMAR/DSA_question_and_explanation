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
Approach:- greedy appraoch(monotonic Stack + intuition based)
    -- element of string ko stack m push kerengen.
    -- jab tak top of stack > new digit ke top pop kerdo
        - jitni baar pop krengen utni baar k-- hoga
    -- ager last m k bach jata h tab, k times jitna stack se pop ker lenge
*/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string removeKdigits(string num, int k)
{
    string ans;
    stack<char> st;

    for(auto digit:num)
    {
        if(k>0){
            while(!st.empty() && st.top()>digit)
            {
                st.pop();
                k--;
                if(k==0) break;
            }
        }

        st.push(digit);
    }

    // k bach gya
    if(k>0){
        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
    }

    // making final answer
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    // removing leading zero
    while(ans.size()>0 && ans.back()=='0') ans.pop_back();

    // get real answer
    reverse(ans.begin(), ans.end());
    

    return ans=="" ? "0" : ans;
}

int main()
{
    string s = "1432219";
    int k=3;

    cout << removeKdigits(s,k) << endl;

    return 0;
}