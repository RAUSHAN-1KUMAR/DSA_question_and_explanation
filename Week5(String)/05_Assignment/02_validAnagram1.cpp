/* -> 242

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

*/

/*
Appraoch:- hashing
    -- frequency of a character in string s will equal to frequency of that same character in string t

Time complexity:- O(n)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isAnagram(string s, string t) 
{
    int frequencyTable[256] = {0};

    // making frequency of string s
    for(int i=0 ; i<s.size(); i++)
    {
        frequencyTable[s[i]]++;
    }


    // frequencyTable got modified w.r.t string t
    for(int i=0 ; i<t.size(); i++)
    {
        frequencyTable[t[i]]--;
    }


    // checking the modifed frequency table
    for(int i=0 ; i<256 ; i++)
    {
        if(frequencyTable[i] != 0) return false;
    }


    return true;
}

int main()
{
    string s = "ac";
    string t = "bb";

    cout << isAnagram(s,t) << endl;;

    return 0;
}
