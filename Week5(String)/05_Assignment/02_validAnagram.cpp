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
Appraoch:- sorting

Time complexity:- O(nlogn)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s.compare(t)==0) return true;

    return false;
}

int main()
{
    string s = "ac";
    string t = "bb";

    cout << isAnagram(s,t) << endl;;

    return 0;
}
