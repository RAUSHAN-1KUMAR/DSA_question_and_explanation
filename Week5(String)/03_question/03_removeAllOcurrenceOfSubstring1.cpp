/* Q.no: 1910
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.


Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".


Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
*/

/*
Approach: implement your own find and erase function
*/


#include<iostream>
#include<string>
using namespace std;

int myFind(string &str, string&sub)
{
    int strLen = str.length();
    int subLen = sub.length();

    for(int i=0 ; i<=(strLen-subLen) ; i++)
    {
        int j=0;

        while(j<subLen && str[i+j]==sub[j]){
            ++j;
        }

        if(j==subLen) return i;
    }

    return -1;
}


void myErase(string &str, int pos, int len)
{
    int strLen = str.length();

    // for invalid case
    if(pos<0 || pos >= strLen || len<0 ) return; 

    for(int i = pos+len ; i<strLen ; i++){
        str[i-len] = str[i];
    }

    str.resize(strLen - len);
}

string removeOccurrences(string s, string part)
{

    while(true)
    {
        int pos = myFind(s,part);

        if(pos==-1) break;
        
        myErase(s,pos,part.length());

    }

    return s;
}

int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";

    string ans = removeOccurrences(str, part);

    cout << ans << endl;

    return 0;
}