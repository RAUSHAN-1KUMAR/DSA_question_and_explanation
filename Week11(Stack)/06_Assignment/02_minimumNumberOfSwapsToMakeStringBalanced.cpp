/* -> 1963

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:
    - It is the empty string, or
    - It can be written as AB, where both A and B are balanced strings, or
    - It can be written as [C], where C is a balanced string.

You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.


Example 1:
Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".

Example 2:
Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".

Example 3:
Input: s = "[]"
Output: 0
Explanation: The string is already balanced.

*/

/*
Approach:- Brute force
    -- pehle jitne bhi valid pairs the sabko remove ker diye stack ka use kerke
    -- ab jo string bache h wo kuch iss tarah honge:
        Example: ][, ]]][[[, ]]]][[[[, etc

        to ab iske liye simple mathematics lagaye h:
            Example: ]]]][[[[
                - half_length = 4
                - even-> ans = half_length/2

            Example: ]]][[[
                - half_length = 3
                - odd-> ans = half_lenfth/2 + 1

*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void fillStack(stack<int> &st, string &s)
{
    for(char ch:s)
    {
        if(ch=='[') st.push(ch);
        else{
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }


/*
Note: jab ham length nikal ke hi apna answer la rhe h to ab string ko modify kerne ki kya zarurat h, wo to stack ke bhi length se nikal sakte h na,
So, below code ki need nhi h -> see next solution
*/

    // modifying our string
    s="";
    while (!st.empty())
    {
        char ch = st.top();
        s.push_back(ch);
        st.pop();
    }

    if(!s.empty())
        reverse(s.begin(), s.end());

}


int minSwaps(string s)
{
    stack<int> st;

    // modifying the string
    fillStack(st,s);

    int size = s.size();

    // if no bracket left
    if(size==0) return 0;

    // applying mathematics to find answer
    int sizeHalf = size/2;

    int ans=0;

    if(sizeHalf&1){
        ans = sizeHalf/2 + 1;
    }
    else{
        ans = sizeHalf/2;
    }

    
    return ans;
}


int main()
{
    string s = "]]][[[";

    int ans = minSwaps(s);

    cout << ans << endl;

    return 0;
}

