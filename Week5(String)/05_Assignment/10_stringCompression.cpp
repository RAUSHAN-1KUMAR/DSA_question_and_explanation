/* -> 443

Given an array of characters 'chars', compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:
    1. If the group's length is 1, append the character to s.
    2. Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
 

Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/


/*
My approach:- two pointer (i=0, j=0), I will use j to check adjacent element and i to modify given vector_of_char 
    -- hame bas last m size return kerna h but ham ache se code implement ker rhe taki if in future wo modified vector_of_char return krna pad jaye to ussi ke liye I am erasing the unwanted in modified char array aur
    -- hame koi extra space nhi use kerna h iska matlab diye gye string m hi modify kerte jao,
    -- i am checking each adjacent by a single variable j and if they are equal then count++; aur ager equal nhi h to previous j wale char ko push kro i.e., chars[i]==chars[j], i++, aur phir uske count ko push kro.
    -- count ko push kerne ke liye pehle usko string me convert ker rhe h then usme loop lagake her ek digit ko push ker rhe answer m.
    -- aur last m return kerne se pehle array ke unwanted elements ko erase ker rhe

Run Length Encoding -> ?
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int compress(vector<char>& chars)
{
    int i=0;
    int j=0;

    int count = 1;

    while(j<chars.size()-1)
    {
        if(chars[j]!=chars[j+1])
        {
            chars[i]=chars[j];
            i++;
            if(count>1){
                string num = to_string(count);
                for(auto ch:num)
                {
                    chars[i] = ch;
                    i++;
                }
            }

            count = 1;
        }
        else{
            count++;
        }

        j++;
    }

    // handling last group
    chars[i]=chars[j];
    i++;
    if(count>1){
        string num = to_string(count);
        for(auto ch:num)
        {
            chars[i] = ch;
            i++;
        }
    }

    // returning answer but first erasing the unwanted
    chars.erase(chars.begin()+i, chars.end());

    for(auto i:chars)
    {
        cout << i << " ";
    }
    cout << endl;

    return chars.size();
}

int main()
{
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','c'};

    cout << compress(chars) << endl;

    return 0;
}