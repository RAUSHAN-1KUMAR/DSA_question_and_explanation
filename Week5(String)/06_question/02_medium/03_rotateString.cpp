/* -> 796

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false
*/

/*
Approach:- mapping of character with integer
    -- mapped the character of s with integer and then applied the same concept as we did in question "checkIfArrayIsSortedRotated".

Note:- but this appraoch is only applicable if there is distinct characters, so we need to find the solution for dublicate characters also.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool rotateString(string s, string goal)
{
    // if size of s is not equal to size of goal
    if(s.size() != goal.size()) return false;


    // creating mappint w.r.t integer value
    int hash[25] = {0};
    int start = 1;
    for(auto ch:s){
        hash[ch-'a'] = start;
        start++;
    }

    // now cheking the rotation of string goal w.r.t integer value of each char
    int count = 0;
    for(int i=1 ; i<goal.size() ; i++)
    {
        char ch2 = goal[i];
        char ch1 = goal[i-1];
        if(hash[ch1-'a']>hash[ch2-'a']) count++;
    }
    char chEnd = goal[goal.size()-1];
    char chStart = goal[0];
    if(hash[chStart-'a']<hash[chEnd-'a'])count++;

    return (count<=1);
}


int main()
{
    string s = "clrwpkwru";
    string goal = "wmpkwruclr";

    if(rotateString(s, goal)) cout << "true";
    else cout << "false";

    return 0;
}