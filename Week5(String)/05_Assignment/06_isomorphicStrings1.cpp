/* -> 205

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

/*
Approach:- mapping
    -- just like we did in: Week5 -> 04_question -> fourth_question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void createMapping(string &str)
{
    char hash[256] = {0};
    char start = 'a';

    for(auto s:str){
        if(hash[s]==0){
            hash[s]=start;
            start++;
        }
    }

    for(int i=0 ; i<str.size() ; i++)
    {
        str[i] = hash[str[i]];
    }
}


bool isIsomorphic(string s, string t) 
{
    createMapping(s);
    createMapping(t);

    return s==t;
}

int main()
{
    string s = "paper";
    string t = "title";

    cout << isIsomorphic(s,t) << endl;

    return 0;
}