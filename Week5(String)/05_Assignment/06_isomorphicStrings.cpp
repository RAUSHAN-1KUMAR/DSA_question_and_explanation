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
    -- but little bit difference, here mapping is done in int array, the respective int of char is stored in mapping array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isIsomorphic(string s, string t) 
{
    // mapping of each character of language 's' to language 't'
    int hash[256] = {0};

    // stores if t[i] char already mapped with s[i].
    bool istCharsMapped[256] = {0};

    //creating mapping
    for(int i=0 ; i<s.size() ; i++)
    {
        if(hash[s[i]]==0 && istCharsMapped[t[i]]==0){
            hash[s[i]] = t[i];
            istCharsMapped[t[i]] == true; 
        } 
    }


    //using mapping
    for(int i=0 ; i<s.size(); i++)
    {
        if(char(hash[s[i]]) != t[i]) return false;
    }

    return true;

}

int main()
{
    string s = "badc";
    string t = "baba";

    cout << isIsomorphic(s,t) << endl;

    return 0;
}