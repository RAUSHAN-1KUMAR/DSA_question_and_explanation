/*
Given a string, you are supposed to find the unique character in that given string using bit mask
*/

/*
Key Idea of Using Bitmask: 
    -- (26)char -> (0-25)bits, i.e., Each bit in the integer represents whether a character is present in the string.
        For example, the 0th bit represents 'a', the 1st bit represents 'b', the 2nd bit represents 'c', and so on.

    -- By setting a bit to 1, we mark that the corresponding character is present. Once all characters are processed, counting the number of 1s in the bitmask gives us the number of unique characters.

How to proceed:-
    -- start with a bitmask of 0 -> 0000...0000(total 26 or you can also take more than that)
    -- For each character in the string:
        i) Calculate its bit position using ch - 'a'.
        ii) Set that bit to 1 using the bitwise OR (|) operation.

        Example: abcc
            For 'a': Bitmask becomes 0001 (binary).
            For 'b': Bitmask becomes 0011 (binary).
            For 'c': Bitmask becomes 0111 (binary).
            For the second 'c': The bitmask stays 0111 (binary), as 'c' is already marked.

    -- At last count the number of set bits in your bitmask
*/

#include<bits/stdc++.h>
using namespace std;

int uniqueChar(string s)
{
    int bitmask=0;
    
    // for each character setting its bit position
    for(char ch:s){
        int bitPos = ch-'a';
        bitmask = (bitmask | (1<<bitPos));
    }

    // now final ans, we are gonna count from right to left
    int ans=0;
    while(bitmask){
        ans += (bitmask&1);
        bitmask = bitmask>>1;
    }

    return ans;
}


int main()
{
    string s="abacc";

    cout << uniqueChar(s) << endl;

    return 0;
}