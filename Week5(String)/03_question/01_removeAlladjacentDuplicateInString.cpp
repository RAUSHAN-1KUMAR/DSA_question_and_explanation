/* Q.no: 1047

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".


Example 2:
Input: s = "azxxzy"
Output: "ay"
*/

/*
My Approach:- two pointer appraoch(i, j=i+1)
    -- if s[i]==s[j] erase them, and then again check from starting or if s[i]!=s[j] then i++.
    -- the loop will terminate if i==s.length().

Note:- not a good approch, time complexity will be very large because at every erase i am rechecking the string from starting
*/


#include<iostream>
#include<string>
using namespace std;

string removeDublicate(string s)
{
    int i=0;
    int erased=0;

    while(i!=s.length())
    {
        int j=i+1;

        if(s[i]==s[j]){
            s.erase(i,2);
            erased=1;
        }

        if(erased==1){
            erased=0;
            i=0;
        }
        else i++;
    }

    return s;
}

int main()
{
    string str = "abbaca";

    string ans = removeDublicate(str);

    cout << ans << endl;

    return 0;
}

