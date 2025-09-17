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
Approach:- making pair of each character to its adjacent characters
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool rotateString(string s, string goal)
{
    // if size of s is not equal to size of goal
    if(s.size() != goal.size()) return false;
      
    // lets make the pair of each adjacent characters of string s
    vector<pair<char,char>> vecPair;
    for(int i=0 ; i<s.size()-1 ; i++)
    {
        char ch1 = s[i];
        char ch2 = s[i+1];
        vecPair.push_back({ch1,ch2});
    }
    char chLast = s[s.size()-1];
    char chfirst = s[0];
    vecPair.push_back({chLast, chfirst});//-> missed the pair of last and first


    // After making pair now checking the pair of string goal matches to pairs or not
    for(int i=0 ; i<goal.size()-1 ; i++)
    {
        char ch1 = goal[i];
        char ch2 = goal[i+1];
        pair<char, char> targetPair = {ch1, ch2};
        auto it = find(vecPair.begin(), vecPair.end(), targetPair);
        if(it == vecPair.end()) return false;
    }
    
    return true;
}


int main()
{
    string s = "clrwmpkwru";
    string goal = "wmpkwruclr";

    if(rotateString(s, goal)) cout << "true";
    else cout << "false";

    return 0;
}