/* -> 2375

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:
    Input: pattern = "IIIDIDDD"
    Output: "123549876"
    Explanation:
    At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
    At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
    Some possible values of num are "245639871", "135749862", and "123849765".
    It can be proven that "123549876" is the smallest possible num that meets the conditions.
    Note that "123414321" is not possible because the digit '1' is used more than once.


Example 2:
    Input: pattern = "DDD"
    Output: "4321"
    Explanation:
    Some possible values of num are "9876", "7321", and "8742".
    It can be proven that "4321" is the smallest possible num that meets the conditions.
*/

/*
Approach:-
    3. using Stack
    -- logic is similar to previous one, i.e., we will be start pushing from 1-9 into our stack in accordance with the pattern string, and 
            i) if we encounter D then we will just push into stack  
            ii) if we encounter I then we will pop the stack and push its top character into ans string, till stack get empty

        TC:- O(n)
        SC:- O(n)
*/

#include<bits/stdc++.h>
using namespace std;

string smallestNumber(string pattern)
{
    int n=pattern.length();

    string ans="";
    int count=1;// a counter that will continuosly incremented from 1 to 9
    stack<char> st;

    for(int i=0 ; i<=n ; i++)
    {
        // I or D -> whatever just push it into stack
        st.push(count+'0'); 
        count++;

        // if I -> then pop and push it into ans string
        if(i==n||pattern[i]=='I'){
            while (!st.empty())
            {
                ans+=st.top(); st.pop();
            }
        }
    }

    return ans;
}


int main()
{
    string pattern="IIIDDI";
    cout <<smallestNumber(pattern) << endl;
    return 0;
}

