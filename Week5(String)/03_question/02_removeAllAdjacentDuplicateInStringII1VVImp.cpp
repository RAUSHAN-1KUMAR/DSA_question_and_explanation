/* Q.No: 1209

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.


Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: First delete "eee" and "ccc", get "ddbbbdaa" Then delete "bbb", get "dddaa"Finally delete "ddd", get "aa"


Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

/*
Approach:- two pointer (nicely)
    -- Explained in notecopy 

Time Complexity: O(n)
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

string removeDuplicate(string s, int k)
{
    int i = 0;
    int j = 0;

    vector<int> count(s.length());

    while(j<s.length())
    {
        s[i]=s[j];

        count[i]=1;

        if(i>0 && s[i]==s[i-1]) count[i] += count[i-1];

        if(count[i]==k) i -= k;  

        i++;
        j++;
    }

    return s.substr(0,i);
}


int main()
{
    string str = "deeedbbcccbdaa";

    string ans = removeDuplicate(str, 3);

    cout << ans << endl;

    return 0;
}



