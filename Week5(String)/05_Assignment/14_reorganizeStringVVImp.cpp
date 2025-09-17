/* -> 767

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
 

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""
*/

/*
Appraoch:- using priority queue(another data structure), but we have not studied queue till now.
    -- so we will solve this question greedly i.e., greedy appraoch
    -- sabse pehle most occurrence character nikal lo and fit it non adjacently and then fill the rest.
        i) we are able to fill the most occurrence character non adjacently then answer exist other wise return "";

-- expalined in notecopy

Note:- we can also that if any character having max freq more than the half of the size of the string than it's 100% that we can't rearrange the string so that any two adjacent character are not the same -> our base case(optional)

Time Complexity:- O(26*n) => O(n)
*/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

string reorganizeString(string s)
{
    int n=s.size();

    int max_freq = INT_MIN;
    char most_freq_char;

    int hash[26] = {0};//-> question has asked only for lowercase aphabet, so (a->97 and z->122) => so we will use hash[s[i]-'a'] instead of hash[s[i]] to point the memory on hash array.
    for(int i=0 ; i<s.size(); i++)
    {
        hash[s[i]-'a']++;

        if(hash[s[i]-'a']>max_freq) // to find mostFreqChar and its frequency
        {
            max_freq=hash[s[i]-'a'];
            most_freq_char=s[i];
        }

        if(hash[s[i]-'a'] > (n+1)/2) // base case
            return "";
    }

    // placing the most_freq_char
    int index=0;
    while(max_freq > 0 && index<s.size()){
        s[index] = most_freq_char;
        max_freq--;
        index += 2;
    }
    
    // we actually don't need it if we have already written our base case
    if(max_freq != 0) return "";//-> if we are not able to place the max_freq character non adjacently

    // if we are able to place it then mark it as 0 frequency
    hash[most_freq_char - 'a'] = 0;

    // lets place the rest of the character
    for(int i=0 ; i<26 ; i++){
        while(hash[i]>0){
            index = index>=s.size() ? 1 : index;
            s[index] = i+'a';
            index += 2;
            hash[i]--;
        }
    }

    return s;
}

int main()
{
    string s = "aac";

    cout << reorganizeString(s) << endl;
    
    return 0;
}