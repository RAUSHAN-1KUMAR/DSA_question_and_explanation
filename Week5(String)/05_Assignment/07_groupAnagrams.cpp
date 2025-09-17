/* -> 49

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
*/

/*
Approach:- sorting + map(string, vector<string>)
    -- identifying anagram w.r.t each string
    -- sort the each string of given vector_of_string and then store the actual string into the map w.r.t its sorted way kyunki ager string ko pehle sort kerenge to aane wala her anagram jo isse match kerta wo usi ke sorted string ke corresponding map m store hoga.
    -- mapping ke baad, last m map ke second value ko push ker denge ans(vector_of_vector_of_string) m, then return ans.

Time Complexity:- O(nmlogm)
Space Complexity:- O(nm)
    ; n -> strs.length()
      m -> length of largest string

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    map<string, vector<string>> mp;

    // creating map
    for(auto str:strs)
    {
        //-> taking each string
        string s = str;

        //-> sort that string
        sort(s.begin(), s.end());

        //-> storing the string w.r.t its sorted way
        mp[s].push_back(str);
    }


    // returning map
    vector<vector<string>> ans;
    for(auto it = mp.begin() ; it!=mp.end() ; it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto string:ans)
    {
        for(auto s:string)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}