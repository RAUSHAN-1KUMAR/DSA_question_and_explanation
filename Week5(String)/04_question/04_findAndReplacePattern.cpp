/* Q.no:- 890

Given a list of strings 'words' and a string 'pattern', return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

(dahati bhasa m boleto: we have a set of string words and a pattern, to words m se kon se string pattern ko follow kerte h wahi ouput m chahiye)

Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"j]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/

/*
Approach:- mapping, just like we did in question no. 1 of this section, in decoding message question.

*/


#include<iostream>
#include<vector>
using namespace  std;

// this function normalizes all the words and patterns into a similar format 
void createUpdateMapping(string &str)
{
    // creating mapping
    char start = 'a';
    char mapping[300] ={};

    for(auto ch: str)
    {
        if(mapping[ch]==0){
            mapping[ch] = start;
            start++;
        }
    }

    // updating str
    for(int i=0 ; i<str.length() ; i++)
    {
        str[i] = mapping[str[i]];
    }

}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;

    // normalizing the pattern
    createUpdateMapping(pattern);

    // normalizing the words and also checking it with pattern
    for(string s: words)
    {
        string tempString = s;

        createUpdateMapping(tempString);

        if(tempString==pattern){
            ans.push_back(s);
        }
    }

    return ans;
}


int main()
{
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"}; 

    string pattern = "abb";

    vector<string> answer = findAndReplacePattern(words, pattern);

    for(auto str:answer)
    {
        cout << str << " ";
    }

    return 0;
}
