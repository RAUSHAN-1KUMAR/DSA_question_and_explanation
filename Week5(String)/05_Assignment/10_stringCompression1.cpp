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
My approach:- two pointer
    -- the appraoch is same as mine but lakshay bhaiyaa only focused on returning the size, so he is not erasing the unwanted in modified char array.
    -- but he is not converting its count to string if it is greater than 1 as i did, he is storing the count as it is using % operator and / operator and then reversing the stored char by using reverse() function.

Run Length Encoding -> ?
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int compress(vector<char>& chars)
{
    int index = 0;
    int count = 1;
    char prev = chars[0];

    for(int i=1 ; i<chars.size() ; i++)
    {
        if(chars[i]==prev){
            count++;
        }
        else{
            chars[index] = prev;
            index++;

            if(count>1){
                int start = index;
                while(count){
                    chars[index] = (count%10) + '0';
                    count /= 10;
                    index++;
                }
                reverse(chars.begin()+start, chars.begin()+index);
            }

            prev = chars[i];
            count = 1;
        }
    }

    // handling last group
    chars[index] = prev;
    index++;
    if(count > 1){
        int start = index;
        chars[index] = (count%10) + '0';
        count /= 10;
        index++;
        reverse(chars.begin()+start, chars.begin()+index);
    }


    return index;
}

int main()
{
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','c'};

    cout << compress(chars) << endl;

    return 0;
}