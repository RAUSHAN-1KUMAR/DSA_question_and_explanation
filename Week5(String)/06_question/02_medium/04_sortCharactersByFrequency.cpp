/* 451

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.


Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

/*
Approach:- hashing + sorting
    -- pehle given string ka freq table banaye h and then uss table ke data ko vector_of_pair(int, char) m store kiye taki usse sort ker sakte.
    -- ab vector_of_pair accending order m sort ho chuka h to ab vector ke last se start krengen kyunki hame highest freq to lowest freq batana h. So, vector m last se iterate kerte waqt uss particular freq ke liye ek while loop start krengen taki uss freq jitna character to ans string m store ker sake.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string frequencySort(string s)
{
    // creating frequency table of each char
    int charHash[300] = {0};
    for(auto ch:s)
    {
        charHash[ch]++;
    }

    // forming the pair w.r.t frequency
    vector<pair<int,char>> freqPair;
    for(int i=0 ; i<300 ; i++)
    {
        if(charHash[i]>0)
        {
            char ch = i;
            int freq = charHash[i];
            freqPair.push_back({freq,ch});
        }
    }

    sort(freqPair.begin(), freqPair.end());

    // forming answer string
    string ans;
    for(int i=freqPair.size()-1 ; i>=0 ; i--)
    {
        int j = freqPair[i].first;
        while (j>0)
        {
            ans.push_back(freqPair[i].second);
            j--;
        }
    }

    return ans;
}


int main()
{
    string s = "AAccccaabBBBBBdd";

    string ans = frequencySort(s);

    cout << ans << endl;

    return 0;
}