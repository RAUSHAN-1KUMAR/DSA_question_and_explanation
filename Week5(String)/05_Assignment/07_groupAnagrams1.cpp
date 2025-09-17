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
Approach:- hashing using map(array[256], vector_of_string)
    -- pichle wala approach m ham sorted string ke corresponding uske actual string ko store ker the map m, kyunki ager koi do string anagram h to uska sorted version same hoga but ye bhi to ho sakta h ki ager koi do string anagram h to uska hashing bhi to equal hoga na. So,
    -- aane wala her string ke corresponting hash bana rhe h ek 256 size ke interger m, and then store the actual string into the map w.r.t its hash, kyunki ager string ka pehle hash array nikalngen to aane wala her anagram jo isse match kerta wo usi ki hash array ke corresponding map m store hoga
    -- mapping ke baad, last m map ke second value ko push ker denge ans(vector_of_vector_of_string) m, then return ans

Time Complexity:- O(nm) less than the sorting approach.
Space Complexity:- O(nm) + map ka size
    ; n -> strs.length()
      m -> length of largest string

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<array>
using namespace std;


// a function whose return type is array
array<int,256> hashing(string s)
{
    array<int,256> hash = {0};

    for(int i=0 ; i<s.size() ; i++)
    {
        hash[s[i]]++;
    }

    return hash;
}



vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    map<array<int, 256>, vector<string>> mp;

    for(auto str:strs)
    {
        // storing the string w.r.t its hash value
        mp[hashing(str)].push_back(str);
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