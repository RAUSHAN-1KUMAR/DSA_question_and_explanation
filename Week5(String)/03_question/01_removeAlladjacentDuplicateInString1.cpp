/* Q.No: 1047

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
Approach:- stack logic (explained in notecopy)
*/


#include<iostream>
#include<string>
using namespace std;

string removeDublicate(string s)
{
    string temp = "";
    int index=0;

    while(index < s.length())
    {
        // checking last character in temp string is same or not to the coming character
        if(temp.length()>0 && temp[temp.length()-1]==s[index]){
            temp.pop_back();
        }
        else{
            temp.push_back(s[index]);
        }

        index++;
    }

    return temp;
}

int main()
{
    string str = "abbaca";

    string ans = removeDublicate(str);

    cout << ans << endl;

    return 0;
}